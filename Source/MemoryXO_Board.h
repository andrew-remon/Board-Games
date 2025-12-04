//MemoryXO_Board.h
#include "BoardGame_Classes.h"
using namespace std;

class MemoryXO_Board : public Board<char> {
public:
    MemoryXO_Board();

    bool update_board(Move<char>* move) override;

    bool is_win(Player<char>* player) override;

    bool is_lose(Player<char>* player) override;

    bool is_draw(Player<char>* player) override;

    bool game_is_over(Player<char>* player) override;

};
