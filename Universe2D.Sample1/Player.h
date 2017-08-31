#pragma once
#include "Unit.h"

class Tile;
class Inventory;

class Player : public Unit {
private:
	Tile* m_PathTile;
	Tile* m_TargetPathTile;

private:
	std::vector<Tile*> m_PathList;
	int m_PathIndex;

private:
	Sprite* m_Sprite;

private:
	Inventory* m_Inventory;

public:
	Player() 
		: m_PathTile(nullptr)
		, m_PathIndex(0)
		, m_TargetPathTile(nullptr) {};
	~Player() {
	};

public:
	CREATE_FUNC(Player);

public:
	bool Initialize();
	
public:
	void Update(float deltaTime);
	void UpdateMovement(float deltaTime);

public:
	void MoveTo(std::vector<Tile*>& pathList);
	void MoveTo(const Vector2& position);

public:
	Tile* GetPathTile() {
		return m_PathTile;
	}
	void SetPathTile(Tile* tile) {
		m_PathTile = tile;
	}
};

