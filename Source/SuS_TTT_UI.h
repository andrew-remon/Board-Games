#pragma once
#include "BoardGame_Classes.h"

/**
 * @class SuS_TTT_UI
 * @brief User Interface class for the SuS Tic-Tac-Toe game.
 *
 * Inherits from the generic `UI<char>` base class and provides
 * SuS Tic-Tac-Toe-specific functionality for player setup and move input.
 *
 * @see UI
 */
class SuS_TTT_UI : public UI<char>
{
public:
	/**
    @brief Constructs a SuS_TTT_UI object.
	*/
    SuS_TTT_UI();
	/**
	* @brief Destructor for SuS_TTT_UI.
    */
    ~SuS_TTT_UI() {};
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

};
