#include <iostream>
#include "board.h"

// Returns a tuple that contains the x and y offsets from a tile's position based on its corridor.
std::tuple<int, int> Board::CorridorOffset(int corridor)
{
	std::tuple<int, int> offset;

	if (corridor == 0)
		offset = {0, -1};
	else if (corridor == 1)
		offset = {-1, 0};
	else if (corridor == 2)
		offset = {0, 1};
	else if (corridor == 3)
		offset = {1, 0};

	return offset;
}

void Board::SetCusorPosition(int x, int y)
{
	std::cout << "\x1b[" << y << ";" << x << "f";
}

void Board::ClearConsole()
{
	std::cout << "\x1b[2J"; 
}

void Board::CallForEachTile(std::function<void(Tile*, int x, int y)> function)
{
	for (int y = 0; y < 6; y++)
		for (int x = 0; x < 6; x++)
			function(board[y][x], y, x);
}

void Board::InsertTile(Tile& tile, int x, int y)
{
	board[y][x] = &tile;
}

void Board::Display()
{
	const int TILE_SIZE_CHARACTERS = 3;

	ClearConsole();

	CallForEachTile([this](Tile* currentTile, int x, int y) -> void 
	{
		if (board[y][x] == nullptr)
			return;

		// set the cursor's position
		int tileDisplayX = (x * TILE_SIZE_CHARACTERS) + 2;
		int tileDisplayY = (y * TILE_SIZE_CHARACTERS) + 2;
		SetCusorPosition(tileDisplayX, tileDisplayY);

		// display the center of tile tile icon
		char tileIcon = '+';
		TileType type = currentTile->Type();
		std::cout << tileIcon;

		// display the tile's corridors
		for (int i = 0; i < 4; i++)
		{
			if (!currentTile->Corridor(i))
				continue;
			
			// set the cursor's position to the speficic corridor off of the center of the tile
			auto [corridorDisplayX, corridorDisplayY] = CorridorOffset(i);
			SetCusorPosition(tileDisplayX + corridorDisplayX, tileDisplayY + corridorDisplayY);

			// display the corridor
			char corridorCharacter = (i % 2 == 0) ? '|' : '-';
			std::cout << corridorCharacter;
		}
	});
}

Board::Board()
{
	for (int y = 0; y < 6; y++)
		for (int x = 0; x < 6; x++)
			board[y][x] = nullptr;
}