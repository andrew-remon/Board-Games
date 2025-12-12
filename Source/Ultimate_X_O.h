#pragma once

#ifndef ULTIMATE_X_O_H
#define ULTIMATE_X_O_H

#include "BoardGame_Classes.h"
using namespace std;

/**
 * @class Ultimate_X_O_Board
 * @brief Represents the Ultimate Tic-Tac-Toe game board.
 *
 * This class inherits from the generic `Board<char>` class and implements
 * the specific logic required for the Ultimate Tic-Tac-Toe game, including
 * move updates, win/draw detection, and game over conditions.
 *
 * @see Board
 */
class Ultimate_X_O_Board : public Board<char> {
public:
	/// @brief Structure to identify small boards within the ultimate board.
	struct smallboardIdentity {
		string name;
		bool x_won;
		bool o_won;
	};

	/// @brief Vector to hold the status of each small board.
	vector <smallboardIdentity> smallBoards = {
		{"TopLeft",   false, false},
		{"TopMid",    false, false},
		{"TopRight",  false, false},
		{"MidLeft",   false, false},
		{"MidMid",    false, false},
		{"MidRight",  false, false},
		{"BotLeft",   false, false},
		{"BotMid",    false, false},
		{"BotRight",  false, false}
	};
	/// @brief Default constructor that initializes an Ultimate Tic-Tac-Toe board.
	Ultimate_X_O_Board();
	/// @brief Destructor for Ultimate_X_O_Board.
	~Ultimate_X_O_Board();
	/**
	* @brief Checks for a win in a specified section of the board.
	* @param Xstart Starting X coordinate.
	* @param Xend Ending X coordinate.
	* @param Ystart Starting Y coordinate.
	* @param Yend Ending Y coordinate.
	* @param symbol The player's symbol to check for a win.
	* @param winFlag Reference to a boolean that will be set to true if a win is detected.
	* @return true if a win is detected, false otherwise.
	*/
	bool checkWin(int Xstart, int Xend, int Ystart, int Yend, char symbol, bool& winFlag);
	/**
	* @brief Loops through a section of the board and fills blank cells with a specified symbol.
	* @param xstart Starting X coordinate.
	* @param ystart Starting Y coordinate.
	* @param xend Ending X coordinate.
	* @param yend Ending Y coordinate.
	* @param symbol The symbol to fill in blank cells.
	*/
	void loopBoardAndFillBlanks(int xstart , int ystart , int xend ,int yend ,char symbol);
	/**
	* @brief Checks if a small board has been won by a player.
	* @param symbol The player's symbol to check for a win.
	* @param s The name of the small board to check.
	* @param b Reference to a boolean that will be set to true if the small board is won.
	*/
	void checksmallWin(char symbol, string& s , bool& b);
	// 9x9 win
	void checkoverallwin();
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
	bool is_win(Player<char>* player) override;
	/**
	* @brief Checks if the game has ended in a draw.
	* @param player Pointer to the player being checked.
	* @return true if all cells are filled and no player has won, false otherwise.
	*/
	bool is_draw(Player<char>* player) override;
	
	/**
	* @brief Checks if the given player has lost the game.
	* @param player Pointer to the player being checked.
	* @return Always returns false (not used in Ultimate Tic-Tac-Toe logic).
	*/
	bool is_lose(Player<char>* player) {return false;};
	/**
	* @brief Determines if the game is over (win or draw).
	* @param player Pointer to the player to evaluate.
	* @return true if the game has ended, false otherwise.
	*/
	bool game_is_over(Player<char>* player) override;
};

/**
 * @class Ultimate_X_O_UI
 * @brief User Interface class for the Ultimate Tic-Tac-Toe game.
 *
 * Inherits from the generic `UI<char>` base class and provides
 * Ultimate Tic-Tac-Toe-specific functionality for player setup and move input.
 *
 * @see UI
 */
class Ultimate_X_O_UI : public UI<char> {
public:
	/**
	* @brief Structure to identify small boards within the ultimate board.
	*/
	struct smallboardIdentity {
		string name;
		bool x_won;
		bool o_won;
	};
	/// @brief Vector to hold the status of each small board.
	vector <smallboardIdentity> smallBoards = {
		{"TopLeft",   false, false},
		{"TopMid",    false, false},
		{"TopRight",  false, false},
		{"MidLeft",   false, false},
		{"MidMid",    false, false},
		{"MidRight",  false, false},
		{"BotLeft",   false, false},
		{"BotMid",    false, false},
		{"BotRight",  false, false}
	};
	/// @brief Constructs an Ultimate_X_O_UI object.
	Ultimate_X_O_UI();
	/// @brief Destructor for Ultimate_X_O_UI.
	~Ultimate_X_O_UI() {};
	/**
	* @brief Creates a player of the specified type.
	* @param name Name of the player.
	* @param symbol Character symbol ('X' or 'O') assigned to the player.
	* @param type The type of the player (Human or Computer).
	* @return Pointer to the newly created Player<char> instance.
	*/
	Player<char>* create_player(string& name, char symbol, PlayerType type);
	/**
	* @brief gets the move from the player.
	* @param player Pointer to the player making the move.
	* @return Pointer to a Move<char> object representing the player's move.
	*/
	Move<char>* get_move(Player<char>* player);
};

#endif // ULTIMATE_X_O_H