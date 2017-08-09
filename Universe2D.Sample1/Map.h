#pragma once
class Tile;
class Map : public Object {
private:
	int m_Width;
	int m_Height;

	Tile*** m_TileMap;
	Object* m_MapObjects;

	std::vector<Tile*> m_OpenList;
	std::vector<Tile*> m_CloseList;

public:
	Map();
	~Map();

public:
	CREATE_FUNC(Map);

public:
	void Update(float deltaTime) override;

public:
	void CreateMap(int width, int height);

public:
	void AddMapObject(Object* object);

public:
	std::vector<Tile*> FindPath(Tile* startTile, Tile* endTile);

public:
	Tile* GetNextTile();
	std::vector<Tile*> GetNeighborTiles(Tile* tile);

public:
	bool IsOpenTile(Tile* tile);
	bool IsCloseTile(Tile* tile);

	bool IsExistTile(int x, int y);

public:
	Tile* GetTileFromPosition(const Vector2& position);

};

