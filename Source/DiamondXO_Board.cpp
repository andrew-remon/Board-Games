// DiamondXO_Board.cpp
#include "DiamondXO_Board.h"

DiamondXO_Board::DiamondXO_Board() : Board<char>(7, 7)
{
    n_moves = 0;
    for (auto& row : board)
    {
        for (auto& cell : row) cell = ' ';
    }
}

bool DiamondXO_Board::update_board(Move<char>* move)
{
    int x = move->get_x();
    int y = move->get_y();
    char symbol = move->get_symbol();

    if (DiamondXO_Board::is_in_diamond(x,y) && (this -> board[x][y] == ' '))
    {
        // Apply move
        this -> n_moves++;
        this -> board[x][y] = symbol;
        return true;
    }
    return false;
}


bool DiamondXO_Board::is_in_diamond(int i, int j) const
{
    int rows = this->rows;
    int cols = this->columns;
    return (i >= 0 && i < rows && j >= 0 && j < cols) && (abs(i - 3) + abs(j - 3) <= 3);
}

// Helper Function
vector<DiamondXO_Board::Line> DiamondXO_Board::find_all_lines(char symbol)
{
    vector<DiamondXO_Board::Line> found_lines;
    pair<int, int> deltas[4] = {
        {0 ,  1},
        {1 ,  0},
        {1 ,  1},
        {1 , -1}
    };
    DiamondXO_Board::Direction direction[4] = {
        DiamondXO_Board::Direction::Horizontal,
        DiamondXO_Board::Direction::Vertical,
        DiamondXO_Board::Direction::DiagonalUp,
        DiamondXO_Board::Direction::DiagonalDown,
    };

    for (int i = 0; i < 7; ++i) 
    {
        for (int j = 0; j < 7; ++j)
        {
            if (DiamondXO_Board::is_in_diamond(i, j) && this->board[i][j] == symbol)
            {
                for (int d = 0; d < 4; ++d)
                {
                    int di = deltas[d].first;
                    int dj = deltas[d].second;

                    int line_length = 0;
                    vector<pair<int, int>> line_coords;

                    for (int k = 0; k < 4; ++k)
                    {
                        int ni = i + k * di;
                        int nj = j + k * dj;

                        if (ni < 0 || ni >= 7 || nj < 0 || nj >= 7) break;

                        if (!DiamondXO_Board::is_in_diamond(ni, nj)) break;

                        if (this->board[ni][nj] == symbol)
                        {
                            line_length++;
                            line_coords.push_back({ ni, nj });
                        }
                        else
                        {
                            break;
                        }
                    }
                    if (line_length == 3 || line_length == 4)
                    {
                        found_lines.push_back({
                            line_length,
                            direction[d],
                            line_coords
                        });
                    }
                }
            }
        }
    }
    return found_lines;
}

bool DiamondXO_Board::is_win(Player<char>* player)
{
    char symbol = player->get_symbol();
    vector<Line> all_lines = find_all_lines(symbol);

    for (size_t a = 0; a < all_lines.size(); ++a) {
        for (size_t b = a + 1; b < all_lines.size(); ++b) {

            const Line& lineA = all_lines[a];
            const Line& lineB = all_lines[b];
    
            bool is_valid_length_pair =
                (lineA.length == 3 && lineB.length == 4) ||
                (lineA.length == 4 && lineB.length == 3);

            if (!is_valid_length_pair) continue;
            
            if (lineA.direction == lineB.direction) continue;

            int intersection_count = 0;

            for (const auto& coordA : lineA.coordinates)
            {
                for (const auto& coordB : lineB.coordinates)
                {
                    if (coordA.first == coordB.first && coordA.second == coordB.second) {
                        intersection_count++;
                    }
                }
            }
            if (intersection_count == 1)
            {
                return true;
            }
        }
    }
    return false;
}

bool DiamondXO_Board::is_lose(Player<char>* player)
{
    return false;
}

bool DiamondXO_Board::is_draw(Player<char>* player)
{
    return (this->n_moves >= 25) && !is_win(player);
}

bool DiamondXO_Board::game_is_over(Player<char>* player)
{
    return(is_win(player) || is_draw(player));
}
