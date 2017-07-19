#pragma once

template<class T, class K>
bool IsContains(T& data, K& value) {
	return std::find(data.begin(), data.end(), value) != data.end();
}

class Tile : public Object {
private:
	Tile* m_ParentTile;

	int m_X, m_Y;
	int m_F, m_G, m_H;

	bool m_IsObstacle;
	Sprite* m_Sprite;

public:
	Tile() : m_ParentTile(nullptr), m_X(0), m_Y(0), m_F(0), m_G(0), m_H(0), m_IsObstacle(false) {};
	~Tile() {};

	static Tile* Create(int x, int y, bool isObstacle, Sprite* sprite) {
		auto tile = new (std::nothrow) Tile();
		if (tile && tile->InitializeWithTile(x, y, isObstacle, sprite)) {
			return tile;
		}

		SAFE_DELETE(tile);
		return nullptr;
	}

public:
	bool InitializeWithTile(int x, int y, bool isObstacle, Sprite* sprite) {
		SetX(x);
		SetY(y);
		SetObstacle(isObstacle);
		SetSprite(sprite);

		GetSprite()->SetParent(this);

		return true;
	}

	void Update(float deltaTime) override {
		Object::Update(deltaTime);

		if (m_Sprite) {
			m_Sprite->Update(deltaTime);
		}
	}

	void Render() override {
		Object::Render();

		if (m_Sprite) {
			m_Sprite->Render();
		}
	}

public:
	Tile* GetParentTile() { return m_ParentTile; }
	void SetParentTile(Tile* tile) { m_ParentTile = tile; }

	int GetX() { return m_X; }
	void SetX(int x) { m_X = x; }

	int GetY() { return m_Y; }
	void SetY(int y) { m_Y = y; }

	int GetF() { return m_F; }
	void SetF(int f) { m_F = f; }

	int GetG() { return m_G; }
	void SetG(int g) { m_G = g; }

	int GetH() { return m_H; }
	void SetH(int h) { m_H = h; }

	bool GetObstacle() { return m_IsObstacle; }
	void SetObstacle(bool isObstacle) { m_IsObstacle = isObstacle; }

	Sprite* GetSprite() { return m_Sprite; }
	void SetSprite(Sprite* sprite) { m_Sprite = sprite; }
};

class Map : public Object {
public:
	Tile*** tileMap;
	int Width, Height;

public:
	Map() : Width(0), Height(0) {
	}
	~Map() {};

public:
	static Map* Create(int width, int height) {
		auto map = new (std::nothrow) Map();
		if (map && map->InitializeWithMap(width, height)) {
			return map;
		}

		SAFE_DELETE(map);
		return nullptr;
	}

public:
	bool Initialize() override {
		return false;
	}
	bool InitializeWithMap(int width, int height) {
		Object::Initialize();

		Width = width;
		Height = height;

		tileMap = new Tile**[height];
		for (int i = 0; i < height; i++) {
			tileMap[i] = new Tile*[width];
			for (int j = 0; j < width; j++) {
				Tile* tile = Tile::Create(j, i, false, Sprite::Create(L"Resources\\ground.png"));
				tile->SetPosition(32 + j * 64, 32 + i * 64);

				tileMap[i][j] = tile;
				AddChild(tile);
			}
		}

		auto block1 = Tile::Create(3, 3, true, Sprite::Create(L"Resources\\box.png"));
		block1->SetPosition(3 * 64 + 32, 3 * 64 + 32);
		tileMap[3][3] = block1;
		AddChild(block1);

		auto block2 = Tile::Create(3, 4, true, Sprite::Create(L"Resources\\box.png"));
		block2->SetPosition(3 * 64 + 32, 4 * 64 + 32);
		tileMap[4][3] = block2;
		AddChild(block2);

		auto block3 = Tile::Create(3, 5, true, Sprite::Create(L"Resources\\box.png"));
		block3->SetPosition(3 * 64 + 32, 5 * 64 + 32);
		tileMap[5][3] = block3;
		AddChild(block3);

		auto startTile = Tile::Create(0, 0, true, Sprite::Create(L"Resources\\player.png"));
		startTile->SetPosition(32, 32);
		AddChild(startTile);

		auto endTile = Tile::Create(5, 5, true, Sprite::Create(L"Resources\\point.png"));
		endTile->SetPosition(5 * 64 + 32, 5 * 64 + 32);
		AddChild(endTile);

		FindPath(0, 0, 5, 5);

		return true;
	}

public:
	void Update(float deltaTime) override {
		Object::Update(deltaTime);

		if (Input::GetInstance()->GetMouseButtonState(MouseButton::Left)) {
			// 선택한 타일을 끝으로 길찾기 시작
		}
	}

public:
	void FindPath(int startX, int startY, int endX, int endY) {
		auto startTile = tileMap[startY][startX];
		auto endTile = tileMap[endY][endX];

		std::vector<Tile*> openList;
		std::vector<Tile*> closeList;

		openList.push_back(startTile);

		while (openList.size() != 0) {
			auto tile = GetPathTile(openList, closeList);
			if (tile == nullptr) {
				printf("길 없음\n");
				break;
			}

			closeList.push_back(tile);
			printf("길 선택 (%d, %d)\n", tile->GetX(), tile->GetY());

			auto sprite = Sprite::Create(L"Resources\\way.png");
			sprite->SetPosition(tile->GetPosition());
			AddChild(sprite);

			if (tile->GetX() == endX && tile->GetY() == endY) {
				// 최종 길 표시
				printf("길 찾기 종료\n");

				break;
			}

			auto neighbors = GetNeighbors(tile);
			for (auto neighbor : neighbors) {
				if (IsContains(closeList, neighbor)) {
					continue;
				}

				int x = neighbor->GetX();
				int y = neighbor->GetY();
				int g = 0;

				if (x - tile->GetX() == 0 || y - tile->GetY()) {
					g = tile->GetG() + 10;
				}

				if (!IsContains(openList, neighbor) || g < neighbor->GetG()) {
					neighbor->SetG(g);
					neighbor->SetH(abs(x - endX) + abs(y - endY));
					neighbor->SetF(neighbor->GetG() + neighbor->GetH());
					neighbor->SetParentTile(tile);

					if (!IsContains(openList, neighbor)) {
						openList.push_back(neighbor);
					}
				}
			}
		}
	}

	// 주변 타일중 이동할 수 있는 타일을 가져옵니다
	std::vector<Tile*> GetNeighbors(Tile* tile) {
		std::vector<Tile*> neighbors;

		int x = tile->GetX();
		int y = tile->GetY();

		if (IsExist(x, y - 1)) {
			neighbors.push_back(tileMap[y - 1][x]);
		}
		if (IsExist(x, y + 1)) {
			neighbors.push_back(tileMap[y + 1][x]);
		}
		if (IsExist(x - 1, y)) {
			neighbors.push_back(tileMap[y][x - 1]);
		}
		if (IsExist(x + 1, y)) {
			neighbors.push_back(tileMap[y][x + 1]);
		}

		return neighbors;
	}

	Tile* GetPathTile(std::vector<Tile*>& openList, std::vector<Tile*>& closeList) {
		Tile* selectedTile = nullptr;
		int selectedTileCost = 1024;

		for (auto openTile : openList) {
			// 닫힌 목록에 있는 타일은 무시함
			if (IsContains(closeList, openTile)) {
				continue;
			}

			auto cost = openTile->GetF();
			if (selectedTileCost > cost) {
				selectedTile = openTile;
				selectedTileCost = cost;
			}
		}

		return selectedTile;
	}

	bool IsExist(int x, int y) {
		// 맵 범위 검사, 이동 가능 여부 검사
		if (x >= 0 && y >= 0 && x < Width && y < Height) {
			if (tileMap[y][x]->GetObstacle() == false)
				return true;
		}

		return false;
	}
};

class SampleScene2 : public Scene {
public:
	SampleScene2();
	~SampleScene2();

public:
	CREATE_FUNC(SampleScene2);

public:
	bool Initialize() override;

public:
	void Update(float deltaTime) override;
	void Render() override;
};