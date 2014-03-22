  #include "CheckersMove.h"
  #include "StringUtils.h"


  std::vector<CheckersSimpleMove> & CheckersMove::get_simple_moves() {
    return simple_moves;
  }
  
CheckersMove::CheckersMove(std::string fg) {
    std::vector<std::string> lma = string_split(fg, '-');
    unsigned int d = unsigned(lma.size()) - unsigned(1);
    CheckersSimpleMove heyy;
    for (unsigned int i = 0; i <d ; i++) {
        heyy.set_start(position_parse(lma[i]));
        heyy.set_end(position_parse(lma[i+1]));
        simple_moves.push_back(heyy);
    }
    // COUT functioniality
//    for (auto & x : bilal.simple_moves) {
//    std::cout << x.start.row << " " << x.start.col << " to " << x.end.row;
//        std::cout << " " << x.end.col << std::endl;
//    }
  }
 
//  void board_move(CheckersBoard & sdf, CheckersMove er) {
//    for (auto & x : er.get_simple_moves()) {
//        board_simple_move(sdf, x);
//    }
//  }


//  void board_capt(CheckersBoard & sdf, int row, int col) {
//    for (auto & dv : sdf.get_light_pieces()) {
//        if (dv.pos.get_row() == row && dv.pos.get_row() == col) {
//            dv.pos.set_row() = -1;
//            dv.pos.set_col() = -1;
//        }  
//    }
//    for (auto & dv : sdf.get_dark_pieces()) {
//        if (dv.pos.get_row() == row && dv.pos.get_row() == col) {
//            dv.pos.set_row() = -1;
//            dv.pos.set_col() = -1;
//        }   
//    }
//  }
//
//  void board_move_and_capture(CheckersBoard & sdf, CheckersMove er) {
//    for (auto & x : er.simple_moves) {
//        board_simple_move(sdf, x);
//        int rowdif = x.start.get_row() - x.end.get_row();
//        int coldif = x.start.get_col() - x.end.get_col();
//        if ((rowdif == 2 || rowdif == -2) && (coldif == 2 || coldif == -2)) {
//            int newrow =x.start.get_row() + x.end.get_row();
//            newrow = newrow/2;
//            int newcol =x.start.get_col() + x.end.get_col();
//            newcol = newcol/2;
//            board_capt(sdf, newrow, newcol);
//        }
//    }    
//  }