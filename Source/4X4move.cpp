#include "4X4move.h"

Move4X4::Move4X4(int from_x, int from_y, int to_x, int to_y, char symbol)
    : Move<char>(to_x, to_y, symbol), from_x(from_x), from_y(from_y) {
}

int Move4X4::get_from_x() const {
    return from_x;
}

int Move4X4::get_from_y() const {
    return from_y;
}