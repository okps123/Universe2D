#pragma once
class Tile;
class Player;
class Map : public Object {
private:
	int m_Width;
	int m_Height;

private:
	Tile*** m_TileMap;
	Object* m_Objects;

private:
	std::vector<Tile*> m_OpenList;
	std::vector<Tile*> m_CloseList;

private:
	Player* m_Player;

public:
	Map();
	~Map();

public:
	static Map* Create(int width, int height) {
		auto map = new (std::nothrow) Map();
		if (map && map->InitializeWithMap(width, height)) {
			return map;
		}

		return nullptr;
	}

public:
	bool InitializeWithMap(int width, int height);

public:
	void Update(float deltaTime) override;

	void UpdatePlayer();

public:
	void AddObject(Object* object);

public:
	Tile* GetTile(int x, int y);
	Tile* GetTile(const Vector2& position);

public:
	std::vector<Tile*> FindPath(Tile* startTile, Tile* endTile);

private:
	Tile* GetNextTile();
	std::vector<Tile*> GetNeighborTiles(Tile* tile);

private:
	bool IsOpenTile(Tile* tile);
	bool IsCloseTile(Tile* tile);

	bool IsExistTile(int x, int y);
};