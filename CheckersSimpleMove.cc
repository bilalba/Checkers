#include "CheckersSimpleMove.h"

// PART 8
CheckersSimpleMove::CheckersSimpleMove() {
    CheckersPosition gh;
    start = gh;
    end = gh;    
}
CheckersSimpleMove::CheckersSimpleMove(std::string zt, std::string rt) {
    start = position_parse(zt);
    end = position_parse(rt);
}

CheckersPosition CheckersSimpleMove::get_start() {
    return start;
}
CheckersPosition CheckersSimpleMove::get_end() {
    return end;
}
void CheckersSimpleMove::set_start(CheckersPosition tf) {
    start = tf;
}

void CheckersSimpleMove::set_end(CheckersPosition tf) {
    end = tf;
}

//  void board_simple_move(CheckersBoard & sdf, CheckersSimpleMove er) {
//    for (auto & dv : sdf.get_dark_pieces()) {
//        if (dv.get_position().get_row() == er.get_start().get_row() &&
//        dv.get_position().get_col() == er.get_start().get_col()) {
//            dv.set_position({er.get_end().get_row(), er.get_end().get_col()});
//        } 
//    }
//    for (auto & dv : sdf.get_dark_pieces()) {
//        if (dv.get_position().get_row() == er.get_start().get_row() &&
//        dv.get_position().get_col() == er.get_start().get_col()) {
//     dv.set_position({er.get_end().get_row(), er.get_end().get_col()}); 
//    }
//  }
//  }