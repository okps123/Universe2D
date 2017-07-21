#pragma once

class Tile : public Object {
private:
	Tile* m_ParentTile;

	int m_X, m_Y;
	int m_F, m_G, m_H;

	bool m_IsObstacle;
	Sprite* m_Sprite;
	Label* m_Label;

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

		m_Label = Label::Create(L"궁서", 12, D3DCOLOR_XRGB(255, 0, 0));
		m_Label->SetPosition(x * 64 + 5, y * 64 + 5);

		return true;
	}

	void Update(float deltaTime) override {
		Object::Update(deltaTime);

		if (m_Sprite) {
			m_Sprite->Update(deltaTime);
		}

		m_Label->SetText(L"G: " + std::to_wstring(GetG())
			+ L"\nH: " + std::to_wstring(GetH())
			+ L"\nF: " + std::to_wstring(GetF()));
		m_Label->Update(deltaTime);
	}

	void Render() override {
		Object::Render();

		if (m_Sprite) {
			m_Sprite->Render();
		}

		m_Label->Render();
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

	Sprite* player;

	std::vector<Tile*> movePointQueue;
	Tile* movePoint;

public:
	Map() : Width(0), Height(0), movePoint(nullptr) {
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

		player = Sprite::Create(L"Resources\\player.png");
		player->SetPosition(32.f, 32.f);
		AddChild(player);

		return true;
	}

public:
	void Update(float deltaTime) override {
		Object::Update(deltaTime);

		if (Input::GetInstance()->GetMouseButtonState(MouseButton::Left) == KeyState::Down) {
			auto position = Input::GetInstance()->GetMousePosition();
			if (position.x < 0 || position.y < 0)
				return;

			if (position.x > 64 * Width || position.y > 64 * Height)
				return;

			if (player->GetPosition().x < 0.f && player->GetPosition().y < 0.f)
				return;

			int px = player->GetPosition().x / 64;
			int py = player->GetPosition().y / 64;
			int tx = position.x / 64;
			int ty = position.y / 64;

			if (!movePointQueue.empty()) {
				movePointQueue.clear();
			}

			for (auto tile : FindPath(px, py, tx, ty)) {
				movePointQueue.push_back(tile);
				printf("%d %d 이동 지점 추가됨\n", tile->GetX(), tile->GetY());
			}
		}

		if (movePoint == nullptr && !movePointQueue.empty()) {
			movePoint = movePointQueue.back();
			movePointQueue.erase(std::find(movePointQueue.begin(), movePointQueue.end(), movePoint));
			printf("%d %d로 이동해야함\n", movePoint->GetX(), movePoint->GetY());
		}

		if (movePoint != nullptr) {
			// movePoint로 이동
			auto targetPosition = movePoint->GetPosition();
			Vector2 position = player->GetPosition();
			bool completeX = false, completeY = false;

			if (position.x < targetPosition.x) {
				position.x += 1.f;
			} else if(position.x > targetPosition.x) {
				position.x -= 1.f;
			} else {
				completeX = true;
			}

			if (position.y < targetPosition.y) {
				position.y += 1.f;
			} else if (position.y > targetPosition.y) {
				position.y -= 1.f;
			} else {
				completeY = true;
			}

			player->SetPosition(position);

			if (completeX && completeY) {
				// 도착
				movePoint = nullptr;
			}
		}
	}

public:
	std::vector<Tile*> FindPath(int startX, int startY, int endX, int endY) {
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
			if (tile->GetX() == endX && tile->GetY() == endY) {
				// 최종 길 표시
				auto result = std::vector<Tile*>();
				result.push_back(tile);

				auto prevTile = tile->GetParentTile();
				while (prevTile->GetX() != startX || prevTile->GetY() != startY) {
					result.push_back(prevTile);
					prevTile = prevTile->GetParentTile();
				}

				return result;
			}

			auto neighbors = GetNeighbors(tile);
			for (auto neighbor : neighbors) {
				if (IsContains(closeList, neighbor)) {
					continue;
				}

				int x = neighbor->GetX();
				int y = neighbor->GetY();
				int g = 0;

				if (x - tile->GetX() == 0 || y - tile->GetY() == 0) {
					g = tile->GetG() + 10;
				}

				if (!IsContains(openList, neighbor) || g < neighbor->GetG()) {
					neighbor->SetG(g);
					neighbor->SetH((abs(x - endX) + abs(y - endY)));
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