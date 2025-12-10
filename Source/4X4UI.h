#pragma once
#include "BoardGame_Classes.h"
#include "4X4move.h" 

/**
* @class UI4X4
* @brief User interface for the 4x4 board game.
* 
* Inherits from the generic UI<char> class and provides
* 4x4-specific functionality for player setup and move input.
* @see UI
*/
class UI4X4 : public UI<char> {
public:
	/**
	* @brief Constructs a UI4X4 object.
    */
    UI4X4(int cell_width = 3);
    /**
	* @brief gets the move from the player.
	* @param player Pointer to the player making the move.
	* @return Pointer to a Move<char> object representing the player's move.
    */
    Move<char>* get_move(Player<char>* player) override;
    /**
	* @brief creates a player of the specified type.
	* @param name: Name of the player.
	* @param symbol: Character symbol assigned to the player.
	* @param type: The type of the player (Human or Computer).
	* @return Pointer to the newly created Player<char> instance.
    */
    Player<char>* create_player(string& name, char symbol, PlayerType type) override;
};