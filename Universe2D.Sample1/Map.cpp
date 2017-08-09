#include "Precompiled.h"
#include "Map.h"
#include "Tile.h"

Map::Map() {}
Map::~Map() {}

void Map::Update(float deltaTime) {
	Object::Update(deltaTime);
}

void Map::CreateMap(int width, int height) {
	m_Width = width;
	m_Height = height;

	m_TileMap = new Tile**[height];
	for (int i = 0; i < height; i++) {
		m_TileMap[i] = new Tile*[width];
		for (int j = 0; j < width; j++) {
			auto tile = Tile::Create();
			tile->Translate(j * Tile::HalfWidth - i * Tile::HalfWidth, i * Tile::HalfHeight / 2 + j * Tile::HalfHeight / 2);
			tile->SetMapPosition(Vector2(j, i));
			tile->SetZOrder(i + j);

			m_TileMap[i][j] = tile;
			AddChild(tile);
		}
	}

	m_MapObjects = Object::Create();
	m_MapObjects->SetZOrder(1000);
	AddChild(m_MapObjects);
}

void Map::AddMapObject(Object* object) {
	object->SetZOrder(abs(object->GetPosition().x) + abs(object->GetPosition().y));
	m_MapObjects->AddChild(object);
}

std::vector<Tile*> Map::FindPath(Tile* startTile, Tile* endTile) {
	if (startTile == endTile)
		return std::vector<Tile*>();

	m_OpenList.clear();
	m_CloseList.clear();

	m_OpenList.push_back(startTile);

	while (m_OpenList.size() != 0) {
		auto nextTile = GetNextTile();
		if (nextTile == nullptr)
			return std::vector<Tile*>();

		m_CloseList.push_back(nextTile);
		nextTile->SetState(TileType::Start);
		auto it = std::find(m_OpenList.begin(), m_OpenList.end(), nextTile);
		m_OpenList.erase(it);

		// ¸ñÀûÁö¿¡ µµÂø
		if (nextTile->GetMapPosition() == endTile->GetMapPosition()) {
			std::vector<Tile*> pathList;
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

	return std::vector<Tile*>();
}

Tile* Map::GetNextTile() {
	Tile* nextTile = nullptr;
	int nextCost = 10000;
	int nextHCost = 10000;

	for (auto openTile : m_OpenList) {
		int cost = openTile->GetCost();
		int hCost = openTile->GetHCost();

		if (cost < nextCost || hCost < nextHCost) {
			if (!IsCloseTile(openTile)) {
				nextTile = openTile;
				nextCost = cost;
				nextHCost = hCost;
			}
		}
	}

	return nextTile;
}
std::vector<Tile*> Map::GetNeighborTiles(Tile * tile) {
	std::vector<Tile*> tiles;

	int x = tile->GetMapPosition().x;
	int y = tile->GetMapPosition().y;

	// ÁÂ
	if (IsExistTile(x - 1, y)) {
		tiles.push_back(m_TileMap[y][x - 1]);
	}
	// »ó
	if (IsExistTile(x, y - 1)) {
		tiles.push_back(m_TileMap[y - 1][x]);
	}
	// ¿ì
	if (IsExistTile(x + 1, y)) {
		tiles.push_back(m_TileMap[y][x + 1]);
	}
	// ÇÏ
	if (IsExistTile(x, y + 1)) {
		tiles.push_back(m_TileMap[y + 1][x]);
	}

	return tiles;
}

bool Map::IsOpenTile(Tile * tile) {
	return IsContains(m_OpenList, tile);
}
bool Map::IsCloseTile(Tile * tile) {
	return IsContains(m_CloseList, tile);
}

bool Map::IsExistTile(int x, int y) {
	if (x >= 0 && y >= 0 && x < m_Width && y < m_Height) {
		if (m_TileMap[y][x]->GetState() != TileType::Block)
			return true;
	}

	return false;
}

Tile* Map::GetTileFromPosition(const Vector2 & position) {
	static float m = 0.5f;

	for (int i = 0; i < m_Height; i++) {
		for (int j = 0; j < m_Width; j++) {
			auto tile = m_TileMap[i][j];

			auto p = tile->GetPosition() + Vector2(0, -Tile::HalfHeight);
			auto p1 = p + Vector2(-Tile::HalfWidth, -Tile::HalfHeight / 2); // ÁÂ
			auto p2 = p + Vector2(0.f, -Tile::HalfHeight); // »ó
			auto p3 = p + Vector2(Tile::HalfWidth, -Tile::HalfHeight / 2); // ¿ì
			auto p4 = p + Vector2(0.f, .0f); // ÇÏ

			float d1 = p1.y - (-m * p1.x);
			float d2 = p2.y - (m * p2.x);
			float d3 = p3.y - (-m * p3.x);
			float d4 = p4.y - (m * p4.x);

			auto ps1 = Sprite::Create(L"Resources\\point.png");
			ps1->SetPosition(p1);
			AddChild(ps1);

			float r1 = -m * position.x - position.y + d1;
			float r2 = m * position.x - position.y + d2;
			float r3 = -m * position.x - position.y + d3;
			float r4 = m * position.x - position.y + d4;

			if (r1 <= 0.f && r2 <= 0.f && r3 >= 0.f && r4 >= 0.f) {
				return tile;
			}
		}
	}

	return nullptr;
}
