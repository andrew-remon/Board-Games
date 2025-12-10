// NumXO_Player.h
#pragma once 
#include <iostream>
#include <set>
#include "BoardGame_Classes.h"
using namespace std;

 // Enum to represent player status as ODD or EVEN
enum class PlayerStatus
{
    ODD,
    Even
};

/**
 * @class NumXO_Player
 * @brief Represents a player in the Numeric X-O game.
 *
 * This class extends the generic `Player<int>` class to include
 * additional information specific to Numeric X-O players, such as
 * their status (odd or even) and available values.
 *
 * @see Player
 */
class NumXO_Player : public Player<int>
{
private:
    PlayerStatus status;
    set<int> available_values;

public:
	// Constructor to initialize a NumXO_Player with name, symbol, type, and status
    NumXO_Player(string n, int s, PlayerType t, PlayerStatus st);

    /**
	* @brief Sets the player's symbol based on their status.
    */
    void set_symbol();

	/**
	* @brief Adds a value to the player's available values.
    * @param value The value to add.
	*/
    bool is_input_symbol_validated(int InputSymbol);

};
