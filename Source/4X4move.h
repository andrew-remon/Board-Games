#pragma once
#include "BoardGame_Classes.h"

/**
 * @class Move4X4
 * @brief Represents a move in a 4x4 board game.
 *
 * This class extends the generic `Move<char>` class to include
 * additional information specific to moves on a 4x4 board, such as
 * the starting coordinates of the move.
 *
 * @see Move
 */
class Move4X4 : public Move<char> {
private:

    int from_x; 
    int from_y; 
public:
    /**
	* @brief Constructs a Move4X4 object with specified coordinates and symbol.
    */
    Move4X4(int from_x, int from_y, int to_x, int to_y, char symbol);
    /**
	* @brief Gets the starting x-coordinate of the move.
	* @return The starting x-coordinate.
    */
    int get_from_x() const;
	/**
	* @brief Gets the starting y-coordinate of the move.
    * @return The starting y-coordinate.
	*/
    int get_from_y() const;
};