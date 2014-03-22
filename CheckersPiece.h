#ifndef __CHECKERSPIECE_H__
#define __CHECKERSPIECE_H__
#include "CheckersPosition.h"

class CheckersPiece {
        private:
        bool crown = false;
        bool capt = false;
        bool dark;
        CheckersPosition pos;
        public:
        bool is_crowned();
        bool is_captured();
        bool is_dark();
        void set_crowned();
        void set_captured();
        void set_dark(bool a);
        bool is_none_piece();
        CheckersPosition get_position();
        void set_position(CheckersPosition df);        
};

CheckersPiece piece_init(CheckersPiece ax);


std::vector<CheckersPosition>
piece_positions_in_direction(CheckersPiece yo, int m);

std::vector<std::vector<CheckersPosition>> piece_neighbors(CheckersPiece dm);

bool piece_isnonepiece(CheckersPiece ax);
std::ostream& operator<<(std::ostream & tv, CheckersPiece az);
#endif  // __CHECKERSPIECE_H__