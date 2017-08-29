#pragma once

enum class TileType {
	None = 0,
	Block,
	Select,
	Start,
	End,
	Path
};

class Tile : public Object {
public:
	static const int Width = 128;
	static const int Height = 78;
	static const int HalfWidth = Width / 2;
	static const int HalfHeight = Height / 2;

private:
	Tile* m_ParentTile;
	Vector2 m_MapPosition;

private:
	TileType m_Type;
	bool m_TypeUpdate;

private:
	Sprite* m_Sprite;

private:
	int m_G;
	int m_H;

public:
	Tile();
	~Tile();

public:
	CREATE_FUNC(Tile);

public:
	bool Initialize() override {
		Object::Initialize();

		return true;
	}

public:
	void Update(float deltaTime) override {
		Object::Update(deltaTime);

		if (m_TypeUpdate) {
			switch (m_Type) {
			case TileType::None:
				m_Sprite = Sprite::Create(L"Resources\\tile_0.png");
				break;
			}
			m_Sprite->SetParent(this);
			m_Sprite->SetAnchorPoint(0.5f, 1.0f);

			m_TypeUpdate = false;
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
	Tile* GetParentTile() {
		return m_ParentTile;
	}
	void SetParentTile(Tile* tile) {
		m_ParentTile = tile;
	}

public:
	const Vector2& GetMapPosition() {
		return m_MapPosition;
	}
	void SetMapPosition(const Vector2& position) {
		m_MapPosition = position;
	}

public:
	const TileType& GetState() {
		return m_Type;
	}
	void SetState(const TileType& state) {
		m_Type = state;
		m_TypeUpdate = true;
	}

public:
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

	int GetCost() {
		return GetGCost() + GetHCost();
	}
};

