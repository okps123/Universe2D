#pragma once

enum class TileState {
	None = 0,
	Block,
	Select,
	Start,
	End,
	Path
};

class IsoTile : public Object {
public:
	static const int Width = 100;
	static const int Height = 50;

private:
	IsoTile* m_ParentTile;

	Vector2 m_MapPosition;

	TileState m_State;
	bool m_StateUpdate;

	Sprite* m_Sprite;

private:
	int m_G;
	int m_H;

public:
	IsoTile() : m_MapPosition(0.f, 0.f), m_State(TileState::None), m_StateUpdate(true), m_Sprite(nullptr) {};
	~IsoTile() {};

public:
	CREATE_FUNC(IsoTile);

public:
	bool Initialize() override {
		Object::Initialize();

		return true;
	}

	void Update(float deltaTime) override {
		Object::Update(deltaTime);

		if (m_StateUpdate) {
			switch (m_State) {
				case TileState::None:
					m_Sprite = Sprite::Create(L"Resources\\isometric\\tile.png");
					break;
				case TileState::Block:
					m_Sprite = Sprite::Create(L"Resources\\isometric\\tile_obst.png");
					break;
				case TileState::Select:
					m_Sprite = Sprite::Create(L"Resources\\isometric\\tile_select.png");
					break;
				case TileState::Start:
					m_Sprite = Sprite::Create(L"Resources\\isometric\\tile_start.png");
					break;
				case TileState::End:
					m_Sprite = Sprite::Create(L"Resources\\isometric\\tile_end.png");
					break;
				case TileState::Path:
					m_Sprite = Sprite::Create(L"Resources\\isometric\\tile_path.png");
					break;
			}
			m_Sprite->SetParent(this);

			m_StateUpdate = false;
		}

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
	IsoTile* GetParentTile() {
		return m_ParentTile;
	}
	void SetParentTile(IsoTile* tile) {
		m_ParentTile = tile;
	}

	const Vector2& GetMapPosition() {
		return m_MapPosition;
	}
	void SetMapPosition(const Vector2& position) {
		m_MapPosition = position;
	}

	const TileState& GetState() {
		return m_State;
	}
	void SetState(const TileState& state) {
		m_State = state;
		m_StateUpdate = true;
	}

	const int& GetGCost() {
		return m_G;
	}
	void SetGCost(const int& g) {
		m_G = g;
	}

	const int& GetHCost() {
		return m_H;
	}
	void SetHCost(const int& h) {
		m_H = h;
	}
};

class SampleScene3 : public Scene {
public:
	int MapWidth;
	int MapHeight;

private:
	IsoTile*** m_TileMap;

	IsoTile* m_StartTile;
	IsoTile* m_EndTile;

public:
	SampleScene3();
	~SampleScene3();

public:
	CREATE_FUNC(SampleScene3);

public:
	bool Initialize() override;

public:
	void Update(float deltaTime) override;
	void UpdateCamera();

public:
	IsoTile* GetTile(const Vector2& position);

public:
public:
	std::vector<IsoTile*> FindPath(IsoTile* startTile, IsoTile* endTile) {
		std::vector<IsoTile*> openList;
		std::vector<IsoTile*> closeList;

		openList.push_back(startTile);

		while (openList.size() != 0) {
			auto tile = GetPathTile(openList, closeList);
			if (tile == nullptr) {
				break;
			}

			closeList.push_back(tile);
			//tile->SetState(TileState::Select);

			// 최종 타일에 도착했으므로 최종 루트를 목록으로 반환합니다
			if (tile->GetMapPosition() == endTile->GetMapPosition()) {
				auto result = std::vector<IsoTile*>();
				//result.push_back(tile);

				auto prevTile = tile->GetParentTile();
				while (prevTile->GetMapPosition() != startTile->GetMapPosition()) {
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

				int x = neighbor->GetMapPosition().x;
				int y = neighbor->GetMapPosition().y;
				int g = 0;

				if (x - tile->GetMapPosition().x == 0 || y - tile->GetMapPosition().y == 0) {
					g = tile->GetGCost() + 10;
				}

				if (!IsContains(openList, neighbor) || g < neighbor->GetGCost()) {
					neighbor->SetParentTile(tile);
					neighbor->SetGCost(g);
					neighbor->SetHCost((abs(x - endTile->GetMapPosition().x) + abs(y - endTile->GetMapPosition().y)));

					if (!IsContains(openList, neighbor)) {
						openList.push_back(neighbor);
					}
				}
			}
		}
	}

	// 주변 타일중 이동할 수 있는 타일을 가져옵니다
	std::vector<IsoTile*> GetNeighbors(IsoTile* tile) {
		std::vector<IsoTile*> neighbors;

		int x = tile->GetMapPosition().x;
		int y = tile->GetMapPosition().y;

		if (IsExist(x, y - 1)) {
			neighbors.push_back(m_TileMap[y - 1][x]);
		}
		if (IsExist(x, y + 1)) {
			neighbors.push_back(m_TileMap[y + 1][x]);
		}
		if (IsExist(x - 1, y)) {
			neighbors.push_back(m_TileMap[y][x - 1]);
		}
		if (IsExist(x + 1, y)) {
			neighbors.push_back(m_TileMap[y][x + 1]);
		}

		return neighbors;
	}
	
	// 이동할 수 있는 타일(openList)중 가장 적은 비용이 드는 타일을 가져옵니다
	IsoTile* GetPathTile(std::vector<IsoTile*>& openList, std::vector<IsoTile*>& closeList) {
		IsoTile* pathTile = nullptr;
		int pathCost = 1024;

		for (auto tile : openList) {
			// 닫힌 목록에 있는 타일은 무시함
			if (IsContains(closeList, tile)) {
				continue;
			}

			auto cost = tile->GetGCost() + tile->GetHCost();
			if (cost < pathCost) {
				pathTile = tile;
				pathCost = cost;
			}
		}

		return pathTile;
	}

	// 이동 가능 여부 검사 함수
	bool IsExist(int x, int y) {
		if (x >= 0 && y >= 0 && x < MapWidth && y < MapHeight) {
			if (m_TileMap[y][x]->GetState() != TileState::Block)
				return true;
		}

		return false;
	}
};

