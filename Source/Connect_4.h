#pragma once

#ifndef CONNECT_4_H
#define CONNECT_4_H

#include "BoardGame_Classes.h"
using namespace std;

/**
 * @class connect_4_Board
 * @brief Represents the Connect 4 game board.
 *
 * This class inherits from the generic `Board<char>` class and implements
 * the specific logic required for the Connect 4 game, including
 * move updates, win/draw detection, and game over conditions.
 *
 * @see Board
 */
class connect_4_Board : public Board<char> {
private:
    char blank_symbol = '.'; 
public:

    /** 
     * @brief Default constructor that initializes a Connect 4 board.
	 */

    connect_4_Board();
    /** 
	 * @brief Destructor for connect_4_Board.
     */
    ~ connect_4_Board();

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
	* @brief Checks if the given player has lost the game.
	* @param player Pointer to the player being checked.
    * @return Always returns false (not used in Connect 4 logic).
	*/
    bool is_lose(Player<char>* player) { return false; };
    /** 
	* @brief Checks if the game has ended in a draw.
	* @param player Pointer to the player being checked.
	* @return true if all cells are filled and no player has won, false otherwise.
    */
    bool is_draw(Player<char>* player) override;
	/**
	* @brief Determines if the game is over (win or draw).
	* @param player Pointer to the player to evaluate.
	* @return true if the game has ended, false otherwise.
    */
    bool game_is_over(Player<char>* player) override;

};
/**
 * @class connect_4_UI
 * @brief User Interface class for the Connect 4 game.
 *
 * Inherits from the generic `UI<char>` base class and provides
 * Connect 4-specific functionality for player setup and move input.
 *
 * @see UI
 */
class connect_4_UI : public UI<char>
{

public:
	/**
    * @brief Constructs a connect_4_UI object.
	*/
    connect_4_UI();
	/**
	* @brief Destructor for connect_4_UI.
    */
    ~connect_4_UI() {};
	/**
	* @brief Creates a player of the specified type.
	* @param name Name of the player.
	* @param symbol Character symbol ('X' or 'O') assigned to the player.
	* @param type The type of the player (Human or Computer).
	*/
    Player<char>* create_player(string& name, char symbol, PlayerType type);
	/**
	* @brief Gets the move from the player.
	* @param player Pointer to the player making the move.
	* @return Pointer to a Move<char> object representing the player's move.
	*/
    virtual Move<char>* get_move(Player<char>* player);
};

#endif // CONNECT_4_H
