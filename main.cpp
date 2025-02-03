#include <iostream>
#include "board.h"
#include "tile.h"

int main()
{
	Board board = Board();
	Tile tile = Tile(CROSS_TILE);

	board.InsertTile(tile, 0, 0);
	board.Display();
}