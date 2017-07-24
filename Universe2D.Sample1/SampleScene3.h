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
	static const int Width = 50;
	static const int Height = 25;

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
	IsoTile()
		: m_ParentTile(nullptr)
		, m_MapPosition(0.f, 0.f)
		, m_State(TileState::None)
		, m_StateUpdate(true)
		, m_Sprite(nullptr)
		, m_G(0)
		, m_H(0) {
	};
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

	const int& GetCost() {
		return GetGCost() + GetHCost();
	}
};

class IsoTower : public Object {
public:
	IsoTower() {};
	~IsoTower() {};

	CREATE_FUNC(IsoTower);

public:
	bool Initialize() {
		auto sprite = Sprite::Create(L"Resources\\isometric\\home.png");
		sprite->SetAnchorPoint(0.5, 1.0);
		AddChild(sprite);

		return true;
	}

	void Update(float deltaTime) {
		Object::Update(deltaTime);
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

	std::vector<IsoTile*> m_OpenList;
	std::vector<IsoTile*> m_CloseList;

	bool m_IsCreateTower;
	IsoTower* m_CreateTower;
	std::vector<IsoTower*> m_Towers;


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
	std::vector<IsoTile*> FindPath(IsoTile* startTile, IsoTile* endTile) {
		m_OpenList.clear();
		m_CloseList.clear();

		m_OpenList.push_back(startTile);

		int count = 0;

		while (m_OpenList.size() != 0) {
			auto nextTile = GetOptimumTile();
			if (nextTile == nullptr) {
				return std::vector<IsoTile*>();
			}

			m_CloseList.push_back(nextTile);

			auto it = std::find(m_OpenList.begin(), m_OpenList.end(), nextTile);
			m_OpenList.erase(it);

			// ¸ñÀûÁö¿¡ µµÂø
			if (nextTile->GetMapPosition() == endTile->GetMapPosition()) {
				std::vector<IsoTile*> pathList;
				auto currentTile = nextTile->GetParentTile();
				while (currentTile->GetMapPosition() != startTile->GetMapPosition()) {
					pathList.push_back(currentTile);
					currentTile = currentTile->GetParentTile();
				}

				return pathList;
			}

			for (auto neighbor : GetNeighborTiles(nextTile)) {
				if (IsCloseTile(neighbor))
					continue;

				neighbor->SetParentTile(nextTile);

				int dx = neighbor->GetMapPosition().x - nextTile->GetMapPosition().x;
				int dy = neighbor->GetMapPosition().y - nextTile->GetMapPosition().y;
				if (dx == 0 || dy == 0) {
					int gCost = neighbor->GetParentTile()->GetGCost() + 10;
					neighbor->SetGCost(gCost);
				}

				int hCost = abs(neighbor->GetMapPosition().x - endTile->GetMapPosition().x)
					+ abs(neighbor->GetMapPosition().y - endTile->GetMapPosition().y);
				neighbor->SetHCost(hCost * 10);

				if (!IsOpenTile(neighbor)) {
					m_OpenList.push_back(neighbor);
				}
			}
		}

		return std::vector<IsoTile*>();
	}

public:
	IsoTile* GetOptimumTile() {
		IsoTile* optimumTile = nullptr;
		int optimumCost = 10000;
		int optimumHCost = 10000;

		for (auto openTile : m_OpenList) {
			int cost = openTile->GetCost();
			int hCost = openTile->GetHCost();

			if (cost < optimumCost || hCost < optimumHCost) {
				if (!IsCloseTile(openTile)) {
					optimumTile = openTile;
					optimumCost = cost;
					optimumHCost = hCost;
				}
			}
		}

		return optimumTile;
	}
	std::vector<IsoTile*> GetNeighborTiles(IsoTile* tile) {
		std::vector<IsoTile*> neighborsTiles;

		int x = tile->GetMapPosition().x;
		int y = tile->GetMapPosition().y;

		// ÁÂ
		if (IsExistTile(x - 1, y)) {
			neighborsTiles.push_back(m_TileMap[y][x - 1]);
		}
		// »ó
		if (IsExistTile(x, y - 1)) {
			neighborsTiles.push_back(m_TileMap[y - 1][x]);
		}
		// ¿ì
		if (IsExistTile(x + 1, y)) {
			neighborsTiles.push_back(m_TileMap[y][x + 1]);
		}
		// ÇÏ
		if (IsExistTile(x, y + 1)) {
			neighborsTiles.push_back(m_TileMap[y + 1][x]);
		}

		return neighborsTiles;
	}

	bool IsOpenTile(IsoTile* tile) {
		return IsContains(m_OpenList, tile);
	}
	bool IsCloseTile(IsoTile* tile) {
		return IsContains(m_CloseList, tile);
	}
	bool IsExistTile(int x, int y) {
		if (x >= 0 && y >= 0 && x < MapWidth && y < MapHeight) {
			if (m_TileMap[y][x]->GetState() != TileState::Block)
				return true;
		}

		return false;
	}
};

