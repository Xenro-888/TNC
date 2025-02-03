#ifndef TILE_H
#define TILE_H

#include <array>

using std::array;

enum TileType {STRAIGHT_TILE, T_TILE, CROSS_TILE};

class Tile
{
	array<bool, 4> corridors;
	TileType type;

public:
	/* getters */

	// Returns the tile's type.
	TileType Type();

	// Checks if the tile's supplied corridor is open/exists.
	bool Corridor(int corridor);

	/* setters */

	/* constructors */

	Tile(TileType initialType);
};

#endif /* TILE_H */