#include "Precompiled.h"
#include "Tile.h"


Tile::Tile()
	: m_ParentTile(nullptr)
	, m_MapPosition(0.f, 0.f)
	, m_Type(TileType::None)
	, m_TypeUpdate(true)
	, m_Sprite(nullptr)
	, m_G(0)
	, m_H(0) {
}


Tile::~Tile() {
}
