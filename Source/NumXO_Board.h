// NumXO_Board.h
#pragma once
#include <iostream>
#include "BoardGame_Classes.h"
using namespace std;

/**
 * @class NumXO_Board
 * @brief Represents the Numeric X-O game board.
 *
 * This class inherits from the generic `Board<int>` class and implements
 * the specific logic required for the Numeric X-O game, including
 * move updates, win/draw detection, and game over conditions.
 *
 * @see Board
 */
class NumXO_Board : public Board<int>
{
private:
    int defaultValue = 0;

public:
	/// @brief Default constructor that initializes a Numeric X-O board.
    NumXO_Board();
	/**
	* @brief Check if a cell is empty (contains the default value).
	* @param cell The cell value to check.
	* @return true if the cell is empty, false otherwise.
    */
    bool is_cell_empty(int cell);
	/**
	* @brief Updates the board with a player's move.
	* @param move Pointer to a Move<int> object containing move coordinates and symbol.
    * @return true if the move is valid and successfully applied, false otherwise.
	*/
    bool update_board(Move<int>* move) override;
	/**
	* @brief Checks if the given player has won the game.
	* @param player Pointer to the player being checked.
	* @return true if the player has a winning line, false otherwise.
	*/
    bool is_win(Player<int>* player) override;
	/**
	* @brief Checks if the given player has lost the game.
	* @param player Pointer to the player being checked.
	* @return Always returns false (not used in Numeric X-O logic).
	*/
    bool is_lose(Player<int>* player) { return false; };
	/**
	* @brief Checks if the game has ended in a draw.
	* @param player Pointer to the player being checked.
	* @return true if all cells are filled and no player has won, false otherwise.
	*/
    bool is_draw(Player<int>* player) override;
	/**
	* @brief Determines if the game is over (win or draw).
	* @param player Pointer to the player to evaluate.
	* @return true if the game has ended, false otherwise.
	*/
    bool game_is_over(Player<int>* player) override;
};
