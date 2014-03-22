#include "CheckersPosition.h"

bool CheckersPosition::operator==(CheckersPosition d) {
    if (row == d.row && col == d.col) {
        return true;
    } else {
        return false;
    }
}

int CheckersPosition::get_row() {
    return row;
}
int CheckersPosition::get_col() {
    return col;
}

void CheckersPosition::set_row(int f) {
    row = f;
}

void CheckersPosition::set_col(int d) {
    col = d;
}
CheckersPosition::CheckersPosition(std::string tr) {
    row = position_parse(tr).get_row();
    col = position_parse(tr).get_col();
}
CheckersPosition::CheckersPosition() {
    row = 0;
    col = 0;
}
CheckersPosition::CheckersPosition(int s, int f) {
    row = s;
    col = f;
}
CheckersPosition position_parse(std::string b) {
    CheckersPosition a; 
    a.set_col(b[0]-'A');
    a.set_row(8 - (b[1]-'0'));
    return a;
} 
