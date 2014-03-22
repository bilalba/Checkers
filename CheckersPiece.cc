#include "CheckersPiece.h"
#include <iostream>


CheckersPosition CheckersPiece::get_position() {
     return pos;
}
void CheckersPiece::set_position(CheckersPosition df) {
     pos = df;
}

bool CheckersPiece::is_none_piece() {
    if (get_position().get_row() == -1) {
        return true;
    } else {
        return false;
    }
}
bool CheckersPiece::is_captured() {
     return capt;
}
bool CheckersPiece::is_crowned() {
     return crown;
}
bool CheckersPiece::is_dark() {
     return dark;
}
void CheckersPiece::set_captured() {
     capt = true;
     pos.set_row(-1);
     pos.set_col(-1);
}
void CheckersPiece::set_crowned() {
     crown = true;
}
void CheckersPiece::set_dark(bool a) {
     dark = a;
}


//  CheckersPiece piece_init(CheckersPiece ax) {
//    ax.set_crowned(false);
//    ax.set_captured(false);
//    ax.set_dark(false);
//    ax.set_position({0, 0});
//    return ax;
//  }




std::vector<CheckersPosition>
piece_positions_in_direction(CheckersPiece yo, int m) {
    std::vector<CheckersPosition> wutt(0);
    int t = 0;
    if ((m == 0 && yo.is_dark() == false) || (m == 0 && yo.is_crowned())) {
        t = 1;
        yo.set_position({yo.get_position().get_row() + 1,
        yo.get_position().get_col() + 1});
    } else if ((m == 1 && yo.is_dark() == false) || (m == 1 &&
    yo.is_crowned())) {
        t = 1;
        yo.set_position({yo.get_position().get_row() + 1,
        yo.get_position().get_col() - 1});
    } else if ((m == 2 && yo.is_dark()) || (m == 2 && yo.is_crowned())) {
        t = 1;
        yo.set_position({yo.get_position().get_row() - 1,
        yo.get_position().get_col() - 1});
    } else if ((m == 3 && yo.is_dark()) || (m == 3 && yo.is_crowned())) {
        t = 1;
        yo.set_position({yo.get_position().get_row() - 1,
        yo.get_position().get_col() + 1});
    }
    
    if (yo.get_position().get_row() >= 0 && yo.get_position().get_row() < 8 &&
    yo.get_position().get_col() >= 0 && yo.get_position().get_col()
    < 8 && t ==1)  {
        CheckersPosition dude;
        dude.set_row(yo.get_position().get_row());
        dude.set_col(yo.get_position().get_row());
        wutt.push_back(dude);  // First time stored here
        //  Second time begins here
        if ((m == 0 && yo.is_dark() == false) || (m == 0 && yo.is_crowned())) {
        yo.set_position({yo.get_position().get_row() + 1,
        yo.get_position().get_col() + 1});
    } else if ((m == 1 && yo.is_dark() == false) || (m == 1 &&
    yo.is_crowned())) {
        t = 1;
        yo.set_position({yo.get_position().get_row() + 1,
        yo.get_position().get_col() - 1});
    } else if ((m == 2 && yo.is_dark()) || (m == 2 && yo.is_crowned())) {
        t = 1;
        yo.set_position({yo.get_position().get_row() - 1,
        yo.get_position().get_col() - 1});
    } else if ((m == 3 && yo.is_dark()) || (m == 3 && yo.is_crowned())) {
        t = 1;
        yo.set_position({yo.get_position().get_row() - 1,
        yo.get_position().get_col() + 1});
    }
    if (yo.get_position().get_row() >= 0 && yo.get_position().get_row() < 8 &&
    yo.get_position().get_col() >= 0 &&
    yo.get_position().get_col() < 8) {
        CheckersPosition thisone;
        thisone.set_row(yo.get_position().get_row());
        thisone.set_col(yo.get_position().get_col());
        wutt.push_back(thisone);
    }
    }
    return wutt;
}


std::vector<std::vector<CheckersPosition>> piece_neighbors(CheckersPiece dm) {
    std::vector<std::vector<CheckersPosition>> dq;
    int df;
    for (df = 3; df >= 0; df--) {
        dq.push_back(piece_positions_in_direction(dm, df));
    }
    return dq;
}


bool piece_isnonepiece(CheckersPiece ax) {
    if (ax.get_position().get_row() == -1) {
        return true;
    } else {
        return false;
    }
}  

std::ostream& operator<<(std::ostream & tv, CheckersPiece az) {
       if (az.is_captured() || piece_isnonepiece(az)) {
            tv << '.';
        } else if (az.is_dark() == false) {
            if (az.is_crowned() == false) {
                tv << 'w';    
            } else if (az.is_crowned() == true) {
            tv << 'W';
            }
        } else if (az.is_dark() == true) {
        if (az.is_crowned() == false) {
            tv << 'b';   
        } else if (az.is_crowned() == true) {
            tv << 'B';
        }
    }
    return tv;
}
    