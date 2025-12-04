//Diamond_Board.h
#include "BoardGame_Classes.h"
using namespace std;

class DiamondXO_Board : public Board<char> {
private:
    
    bool is_in_diamond(int i, int j) const;


public:
    enum Direction {
        Horizontal,
        Vertical,
        DiagonalUp,
        DiagonalDown
    };

    struct Line {
        int length;
        Direction direction;
        vector<pair<int, int>> coordinates;
    };

    vector<Line> find_all_lines(char symbol);
    
    DiamondXO_Board();

	bool update_board(Move<char>* move) override;

    bool is_win(Player<char>* player) override;

    bool is_lose(Player<char>* player) override;

    bool is_draw(Player<char>* player) override;

    bool game_is_over(Player<char>* player) override;

};
