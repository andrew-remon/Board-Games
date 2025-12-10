// NumXO_UI.h
#pragma once
#include "BoardGame_Classes.h"
#include "NumXO_Player.h"

/**
 * @class NumXO_UI
 * @brief User Interface class for the Numeric X-O game.
 *
 * Inherits from the generic `UI<int>` base class and provides
 * Numeric X-O-specific functionality for player setup and move input.
 *
 * @see UI
 */
class NumXO_UI : public UI<int>
{
public:
    /**
	 * @brief Constructs a NumXO_UI object.
     */
    NumXO_UI();
	/**
	* @brief Destructor for NumXO_UI.
    */
    ~NumXO_UI() {};
	/**
	* @brief Creates a player of the specified type.
	* @param name Name of the player.
	* @param symbol Integer symbol assigned to the player.
	* @param type The type of the player (Human or Computer).
	* @return Pointer to the newly created Player<int> instance.
	*/
    Player<int>* create_player(string& name, int symbol, PlayerType type) override;
	/**
	* @brief gets the move from the player.
	* @param player Pointer to the player making the move.
	* @return Pointer to a Move<int> object representing the player's move.
	*/
    Move<int>* get_move(Player<int>* player) override;
	/**
	* @brief sets up the players for the game.
	*/
    Player<int>** setup_players() override;
	/**
	* @brief gets the player's status choice (ODD or EVEN).
	* @param player_label
	* @param options
	* @return PlayerStatus
	*/
    PlayerStatus get_player_status_choice(string player_label, const vector<string>& options);
};
