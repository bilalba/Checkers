#include "CheckersBoard.h"
#include "StringUtils.h"
#include <iostream>
bool CheckersBoard::check_move() {
    return mover;
}
void CheckersBoard::change_move() {
    if (mover) {
        mover = false;   //  whites turn
    } else {
        mover = true;   //  blacks turn
    }
}
int CheckersBoard::validate(CheckersMove ht) {
    int midd = 0;
    int newrow = 0;
    int newcol = 0;
    int rty = 0;
    if (winner() == 0) {
        CheckersPosition fg = ht.get_simple_moves()[0].get_start();
        CheckersPosition dr = ht.get_simple_moves()[0].get_end();
        CheckersPiece dv =board_get_piece_at(fg.get_row(), fg.get_col());
        CheckersPiece en =board_get_piece_at(dr.get_row(), dr.get_col());
        /// CODE TO JUMP TWO
            int rowdif = fg.get_row() - dr.get_row();
            int coldif = fg.get_col() - dr.get_col();
            if ((rowdif == 2 || rowdif == -2) &&
            (coldif == 2 || coldif == -2)) {
            newrow =fg.get_row() + dr.get_row();
            newrow = newrow/2;
            newcol =fg.get_col() + dr.get_col();
            newcol = newcol/2;
            midd = 1;
            }
            ///// ---------------
            if (dv.is_dark()) {   
                if ((rowdif == 1 || dv.is_crowned()) &&
                (coldif == 1 || coldif == -1)) {
            rty = 1;
        }
        if ((rowdif == -2 || dv.is_crowned()) &&
        (coldif == 2 || coldif == -2)) {
            rty = 1;
        }
            if (check_move() == false) {
                return 2;
            }
            if (midd == 1) {
                CheckersPiece mid =board_get_piece_at(newrow, newcol);
            if (mid.is_dark() || mid.get_position().get_row() == -1) {
            return 5;
            }
            }
        }
        if (dv.is_dark() == false) {
            if ((rowdif == -1 || dv.is_crowned()) &&
            (coldif == 1 || coldif == -1)) {
            rty = 1;
        }
        if ((rowdif == 2 || dv.is_crowned()) && (coldif == 2 || coldif == -2)) {
            rty = 1;
        }
            if (check_move() == true) {
                return 2;
            }
            if (midd == 1) {
                CheckersPiece mid =board_get_piece_at(newrow, newcol);
            if (mid.is_dark() == false || mid.get_position().get_row() == -1) {
            return 5;
            }
            }
        }
        
        if (dv.get_position().get_row() == -1) {
     return 3;
     }
     if (en.get_position().get_row() != -1) {
            return 4;
        }
        
        // 6 CONDITION
        if (rty == 0) {
            return 6;
        }
        
        
    } else {
        return 1;
    }
    return 0;
}
int CheckersBoard::winner() {
    int di = 0;
    int  li = 0;
    int x;
    for (auto & dv : light_pieces) {
        if (dv.is_captured() || dv.is_none_piece()) {
                li = li + 1;
            }
    }
    for (auto & dv : dark_pieces) {
        if (dv.is_captured() || dv.is_none_piece()) {
                di = di + 1;
            }
    }
    if (li == 12) {
        x = 1;
    } else if (di == 12) {
        x = 2;
    } else {
        x = 0;
    }
    return x;
}

void CheckersBoard::set_none_piece() {
    none_piece.set_position({-1, -1});
}
CheckersPiece CheckersBoard::get_none_piece() {
    return none_piece;
}

void CheckersBoard::set_light_pieces(std::vector<CheckersPiece> td) {
    light_pieces = td;
}
void CheckersBoard::set_dark_pieces(std::vector<CheckersPiece> td) {
    dark_pieces = td;
}

std::vector<CheckersPiece>& CheckersBoard::get_light_pieces() {
    return light_pieces;    
}

std::vector<CheckersPiece>& CheckersBoard::get_dark_pieces() {
    return dark_pieces;
}

void CheckersBoard::move(CheckersMove ds) {
    change_move();
    for (auto & x : ds.get_simple_moves()) {
        simple_move(x);
        for (auto & dv : light_pieces) {
//            std::cout << dv.get_position().get_row() << " ";
        if (dv.get_position().get_row() == 7) {            
            dv.set_crowned();
        }  
    }
    for (auto & dv : dark_pieces) {
        if (dv.get_position().get_row() == 0) {
            dv.set_crowned();
        }   
    }
        
        int rowdif = x.get_start().get_row() - x.get_end().get_row();
        int coldif = x.get_start().get_col() - x.get_end().get_col();
        if ((rowdif == 2 || rowdif == -2) && (coldif == 2 || coldif == -2)) {
            int newrow =x.get_start().get_row() + x.get_end().get_row();
            newrow = newrow/2;
            int newcol =x.get_start().get_col() + x.get_end().get_col();
            newcol = newcol/2;
            for (auto & dv : light_pieces) {
        if (dv.get_position().get_row() == 
        newrow && dv.get_position().get_col() == newcol) {
            dv = none_piece;
        }  
    }
    for (auto & dv : dark_pieces) {
        if (dv.get_position().get_row() == 
        newrow && dv.get_position().get_col() == newcol) {
            dv = none_piece;
        }   
    }
  };
        }
    }
  

void CheckersBoard::simple_move(CheckersSimpleMove er) {
    std::vector<CheckersPiece> lm(0);
    for (auto & dv : get_light_pieces()) {
        if (dv.get_position().get_row() == er.get_start().get_row() &&
        dv.get_position().get_col() == er.get_start().get_col()) {
            dv.set_position({er.get_end().get_row(), er.get_end().get_col()});
        } 
        lm.push_back(dv);
    }
    set_light_pieces(lm);
    std::vector<CheckersPiece> sm(0);
    for (auto & dv : get_dark_pieces()) {
        if (dv.get_position().get_row() == er.get_start().get_row() &&
        dv.get_position().get_col() == er.get_start().get_col()) {
            dv.set_position({er.get_end().get_row(), er.get_end().get_col()});
        }
        sm.push_back(dv);
    }
    set_dark_pieces(sm);
}
CheckersPiece & CheckersBoard::operator[](CheckersPosition d) {
    for (auto & dv : get_light_pieces()) {
        if (dv.get_position().get_row() == d.get_row() &&
        dv.get_position().get_col() == d.get_col()) {
            return dv;
        }  
    }
    for (auto & dv : get_dark_pieces()) {
        if (dv.get_position().get_row() == d.get_row() &&
        dv.get_position().get_col() == d.get_col()) {
            return dv;
        }   
    }
        return none_piece;
}
CheckersBoard::CheckersBoard(std::string zz, std::string yy) {
    std::vector<std::string> uv = string_split(zz, ',');
    std::vector<std::string> uc = string_split(yy, ',');
       set_none_piece();
       std::vector<CheckersPiece> nv(0);
    for (auto & dv : dark_pieces) {
        dv.set_dark(true);
        dv = get_none_piece();
        nv.push_back(dv);
    }
    set_dark_pieces(nv);
    std::vector<CheckersPiece> xd(0);
        for (auto & dv : light_pieces) {
        dv.set_dark(false);
        dv = get_none_piece();
        xd.push_back(dv);
        }
        set_light_pieces(xd);
    unsigned int i = 0;
    for (auto & df : uv) {
        CheckersPosition cd = position_parse(df);
        dark_pieces[i].set_position(cd);
        dark_pieces[i].set_dark(true);
        i = i + 1;
    } 
    i = 0;
    for (auto & df : uc) {
        CheckersPosition cd = position_parse(df);
        light_pieces[i].set_position(cd);
        light_pieces[i].set_dark(false);
        i = i + 1;
    } 
}

CheckersBoard::CheckersBoard() {
    int rowdem = 0;
    int cowdem = 1;
    std::vector<CheckersPiece> xd(0);
    for (auto & dv : get_light_pieces()) {
        dv.set_dark(false);
        dv.set_position({rowdem, cowdem});
        cowdem = cowdem + 2;
        if (cowdem >= 8) {
            if (rowdem  == 0) {
                cowdem = cowdem - 2;
            }
            rowdem = rowdem + 1;
            cowdem = cowdem - 7;
        }
        xd.push_back(dv);
// std::cout << "(" << dv.pos.row << "," << dv.pos.col << ")" << std::endl;
    }
    set_light_pieces(xd);
    rowdem = 7;
    cowdem = 0;
    std::vector<CheckersPiece> nv(0);
    for (auto & dv : get_dark_pieces()) {
        dv.set_dark(true);
        dv.set_position({rowdem, cowdem});
        cowdem = cowdem + 2;
        if (cowdem >= 8) {
            if (rowdem == 6) {
                cowdem = cowdem -2;
            }
            rowdem = rowdem - 1;
            cowdem = cowdem - 7;
        }
        nv.push_back(dv);
    }
    set_dark_pieces(nv);
    set_none_piece();
    }
//  CheckersBoard board_init() {
//    CheckersBoard aw;
//    int rowdem = 0;
//    int cowdem = 1;
//    for (auto & dv : aw.light_pieces) {
//        dv.dark = false;
//        dv.pos.col = cowdem;
//        dv.pos.row = rowdem;
//        cowdem = cowdem + 2;
//        if (cowdem >= 8) {
//            if (rowdem  == 0) {
//                cowdem = cowdem - 2;
//            }
//            rowdem = rowdem + 1;
//            cowdem = cowdem - 7;
//        }
////   std::cout << "(" << dv.pos.row << "," << dv.pos.col << ")" << std::endl;
//    }
//    rowdem = 7;
//    cowdem = 0;
//    for (auto & dv : aw.dark_pieces) {
//        dv.dark = true;
//        dv.pos.col = cowdem;
//        dv.pos.row = rowdem;
//        cowdem = cowdem + 2;
//        if (cowdem >= 8) {
//            if (rowdem == 6) {
//                cowdem = cowdem -2;
//            }
//            rowdem = rowdem - 1;
//            cowdem = cowdem - 7;
//        }
//    }
//    aw.none_piece.pos.row = -1;
//    aw.none_piece.pos.col = -1;
//    return aw;
//  }
//   Piece_isNonePiece (Part 3)




CheckersPiece & CheckersBoard::board_get_piece_at(int row, int col) {
    for (auto & dv : light_pieces) {
        if (dv.get_position().get_row() == row &&
        dv.get_position().get_col() == col) {
            return dv;
        }  
    }
    for (auto & dv : dark_pieces) {
        if (dv.get_position().get_row() == row &&
        dv.get_position().get_col() == col) {
            return dv;
        }   
    }
        return none_piece;
} 

//
//  int board_print(CheckersBoard asd) {
//    for (int g = 0; g <8 ; g++) {
//        std::cout << 8-g << " ";
//        for (int i = 0; i <8 ; i++) {
//         CheckersPiece trr = board_get_piece_at(asd, g, i);
//         if (piece_isnonepiece(trr)) {
//             std::cout <<  ".";
//         } else {
//             piece_print(trr);
//         }
//         if (i <= 6) {
//            // std::cout << " ";
//         }
//        }
//        std::cout << std::endl;
//    }
//    std::cout << "  ABCDEFGH";
//    return 0;
//  }
CheckersPiece get_piece_at(CheckersBoard aw, int row, int col) {
    for (auto & dv : aw.get_light_pieces()) {
        if (dv.get_position().get_row() == row &&
        dv.get_position().get_col() == col) {
            return dv;
        }  
    }
    for (auto & dv : aw.get_dark_pieces()) {
        if (dv.get_position().get_row() == row &&
        dv.get_position().get_col() == col) {
            return dv;
        }   
    }
        return aw.get_none_piece();
}
std::ostream& operator<<(std::ostream & rd, CheckersBoard asd) {
    for (int g = 0; g <8 ; g++) {
        rd << 8-g << " ";
        for (int i = 0; i <8 ; i++) {
         CheckersPiece trr = get_piece_at(asd, g, i);
                     rd << trr;
               if (i <= 6) {
            // std::cout << " ";
         }
        }
        rd << std::endl;
    }
    rd << "  ABCDEFGH";
    return rd;
}
    