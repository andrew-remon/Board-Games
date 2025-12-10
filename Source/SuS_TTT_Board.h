#pragma once
#include <iostream>
#include <map>
#include "BoardGame_Classes.h"
using namespace std;

/**
 * @class SuS_TTT_Board
 * @brief Represents the SuS Tic-Tac-Toe game board.
 *
 * This class inherits from the generic `Board<char>` class and implements
 * the specific logic required for the SuS Tic-Tac-Toe game, including
 * move updates, win/draw detection, and game over conditions.
 *
 * @see Board
 */

class SuS_TTT_Board : public Board<char>
{
private:
    const char defaultValue = '.';
    bool isFirst = true;

public:
    //======= Variables =======
    int player1Sequences = 0;
    int player2Sequences = 0;
    
    //=======  Methods  =======
    /**
    * @brief Default constructor that initializes a SuS Tic-Tac-Toe board.
	*/
    SuS_TTT_Board();
	/**
	* @brief Check the latest board state and update the map with occupied symbols.
	* @param x A map to track occupied symbols on the board.
    */
    void checkLatestBoard(map<string, bool>& x );
	/**
	* @brief Check if a cell is empty (contains the default value).
	* @param cell The cell value to check.
	* @return true if the cell is empty, false otherwise.
    */
    bool is_cell_empty(char cell);
	/**
	* @brief Updates the board with a player's move.
	* @param move Pointer to a Move<char> object containing move coordinates and symbol.
	* @return true if the move is valid and successfully applied, false otherwise.
    */

    bool update_board(Move<char>* move) override;
	/**
	* @brief Checks if the given player has won the game.
	* @param player Pointer to the player being checked.
	* @return true if the player has a winning line, false otherwise.
    */
    bool is_win(Player<char>* player) override ;
	/**
	* @brief Checks if the game has ended in a draw.
	* @param player Pointer to the player being checked.
	* @return true if all cells are filled and no player has won, false otherwise.
    */
    bool is_draw(Player<char>* player) override ;
	/**
	* @brief Determines if the game is over (win or draw).
	* @param player Pointer to the player to evaluate.
    * @return true if the game has ended, false otherwise.
	*/
    bool game_is_over(Player<char>* player) override ;
	/**
	* @brief Checks if the given player has lost the game.
	* @param player Pointer to the player being checked.
	* @return true if the player has lost, false otherwise.
	*/
    bool is_lose(Player<char>* player) ;
};