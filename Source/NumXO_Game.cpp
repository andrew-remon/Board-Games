#include <iostream>
#include "NumXO_Board.h"
#include "NumXO_Player.h"
#include "NumXO_UI.h"
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    UI<int>* ui = new NumXO_UI();

    Board<int>* board = new NumXO_Board();

    Player<int>** players = ui->setup_players();

    // Create the game manager with the board and the array of players.
    GameManager<int> x_o_game(board, players, ui);

    // Run the game loop.
    x_o_game.run();

    // --- Cleanup ---
    // Delete the dynamically allocated board object.
    delete board;

    // Delete the individual player objects.
    for (int i = 0; i < 2; ++i)
        delete players[i];

    // Delete the dynamically allocated array of player pointers itself.
    delete[] players;

    return 0;
}
