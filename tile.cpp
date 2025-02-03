#include "tile.h"

TileType Tile::Type() { return type; }

bool Tile::Corridor(int corridor) { return corridors[corridor]; }

Tile::Tile(TileType initialType)
{
	type = initialType;

	if (type == STRAIGHT_TILE)
		corridors = {true, false, true, false};
	else if (type == T_TILE)
		corridors = {true, true, true, false};
	else if (type == CROSS_TILE)
		corridors = {true, true, true, true};
}