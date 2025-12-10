// MemoryXO_UI.h
#pragma once
#include "BoardGame_Classes.h"

/**
 * @class MemoryXO_UI
 * @brief User Interface class for the Memory X-O game.
 *
 * Inherits from the generic `UI<char>` base class and provides
 * Memory X-O-specific functionality for player setup and move input.
 *
 * @see UI
 */

class MemoryXO_UI : public UI<char>
{
public:
    /**
     * @brief Constructs a MemoryXO_UI object.
	 */

    MemoryXO_UI();
    /**
	* @brief Destructor for MemoryXO_UI.
    */

    ~MemoryXO_UI() {};
	/**
	* @brief Creates a player of the specified type.
	* @param name Name of the player.
	* @param symbol Character symbol ('X' or 'O') assigned to the player.
	* @param type The type of the player (Human or Computer).
	* @return Pointer to the newly created Player<char> instance.
    */
    Player<char>* create_player(string& name, char symbol, PlayerType type) override;
	/**
	* @brief gets the move from the player.
	* @param player Pointer to the player making the move.
	* @return Pointer to a Move<char> object representing the player's move.
	*/
    Move<char>* get_move(Player<char>* player) override;
	/**
	* @brief sets up the players for the game.
	* @return Pointer to an array of two Player<char> instances.
	*/
    Player<char>** setup_players() override;
	/**
	* @brief displays the current board matrix in formatted form.
	* @param matrix 2D vector representing the board state.
	*/
    void display_board_matrix(const vector<vector<char>>& matrix) const override;
};