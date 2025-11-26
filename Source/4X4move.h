#pragma once
#include "BoardGame_Classes.h"

class Move4X4 : public Move<char> {
private:
    int from_x; 
    int from_y; 
public:
    Move4X4(int from_x, int from_y, int to_x, int to_y, char symbol);
    int get_from_x() const;
    int get_from_y() const;
};