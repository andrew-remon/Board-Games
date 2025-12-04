// PyramidXO_UI.h
#pragma once
#include "BoardGame_Classes.h"

class PyramidXO_UI : public UI<char>
{
private:
    bool is_in_pyramid(int i, int j) const;

public:
    PyramidXO_UI();

    ~PyramidXO_UI() {};

    Player<char>* create_player(string& name, char symbol, PlayerType type) override;

    Move<char>* get_move(Player<char>* player) override;

    Player<char>** setup_players() override;

    void display_board_matrix(const vector<vector<char>>& matrix) const override;
};