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

public:
	int GetCost() {
		return GetGCost() + GetHCost();
	}

public:
	static bool IsCollide(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, Vector2 p) {
		float d1 = p1.y - (-0.5f * p1.x);
		float d2 = p2.y - (0.5f * p2.x);
		float d3 = p3.y - (-0.5f * p3.x);
		float d4 = p4.y - (0.5f * p4.x);

		float r1 = -0.5f * p.x - p.y + d1;
		float r2 = 0.5f * p.x - p.y + d2;
		float r3 = -0.5f * p.x - p.y + d3;
		float r4 = 0.5f * p.x - p.y + d4;

		if (r1 <= 0.f && r2 <= 0.f && r3 >= 0.f && r4 >= 0.f) {
			return true;
		}

		return false;
	}
};

