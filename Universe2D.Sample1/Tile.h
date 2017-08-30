#pragma once

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
	bool m_Moveable;

private:
	int m_G;
	int m_H;

public:
	Tile()
		: m_ParentTile(nullptr)
		, m_MapPosition(0.f, 0.f)
		, m_Moveable(true)
		, m_G(0)
		, m_H(0) {};
	~Tile() {};

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
	}
	void Render() override {
		Object::Render();
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

	bool GetMoveable() {
		return m_Moveable;
	}
	void SetMoveable(bool isMoveable) {
		m_Moveable = isMoveable;
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

