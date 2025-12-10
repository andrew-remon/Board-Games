//MemoryXO_Board.h
#include "BoardGame_Classes.h"
using namespace std;


/**
 * @class MemoryXO_Board
 * @brief Represents the Memory X-O game board.
 *
 * This class inherits from the generic `Board<char>` class and implements
 * the specific logic required for the Memory X-O game, including
 * move updates, win/draw detection, and game over conditions.
 *
 * @see Board
 */
class MemoryXO_Board : public Board<char> {
public:
	/// @brief Default constructor that initializes a Memory X-O board.
    MemoryXO_Board();
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
	* @return true if the player has lost, false otherwise.
	*/
    bool is_lose(Player<char>* player) override;
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
