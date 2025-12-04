//PyramidXO_Board.h
#include "BoardGame_Classes.h"
using namespace std;

class PyramidXO_Board : public Board<char> {
public:
    PyramidXO_Board();

    bool update_board(Move<char>* move) override;

    bool is_win(Player<char>* player) override;

    bool is_lose(Player<char>* player) override;

    bool is_draw(Player<char>* player) override;

    bool game_is_over(Player<char>* player) override;

    static bool is_in_pyramid(int i, int j);
};
