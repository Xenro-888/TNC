#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <functional>
#include <tuple>
#include "tile.h"
#include "prisoner.h"

using std::array, std::tuple;

class Board
{
	array<array<Tile*, 6>, 6> board;
	array<Prisoner, 5> prisoners;

public:
	/* getters */

	/* setters */

	/* methods*/

	// Returns a tuple that contains the x and y offsets from a tile's position based on its corridor.
	std::tuple<int, int>CorridorOffset(int corridor);


	// Sets the position of the console's cursor.
	void SetCusorPosition(int x, int y);

	// Clears the console.
	void ClearConsole();

	// Calls the given std::function for every tile on the board.
	// The std::function takes the current tile, and its x and y coordinates as parameters.
	void CallForEachTile(std::function<void(Tile*, int x, int y)> function);

	// Inserts a tile on the board at the specified position.
	void InsertTile(Tile& tile, int x, int y);

	// Displays the board.
	void Display();

	/* constructors */
	Board();
};

#endif