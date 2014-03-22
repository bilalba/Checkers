#ifndef __CHECKERSBOARD_H__
#define __CHECKERSBOARD_H__
#include <vector>

#include "CheckersPiece.h"
#include "CheckersPosition.h"
#include "CheckersSimpleMove.h"
#include "CheckersMove.h"
class CheckersBoard {
        private:
std::vector<CheckersPiece> light_pieces = std::vector<CheckersPiece>(12);
        std::vector<CheckersPiece> dark_pieces = std::vector<CheckersPiece>(12);
        CheckersPiece none_piece;
        bool mover = false;   //   white move first
        public:
        bool check_move();
        void change_move();
        std::vector<CheckersPiece>& get_light_pieces();
        std::vector<CheckersPiece>& get_dark_pieces();
        CheckersPiece get_none_piece();
        void set_light_pieces(std::vector<CheckersPiece> dm);
        void set_dark_pieces(std::vector<CheckersPiece> df);
        void set_none_piece();
        CheckersBoard();
        CheckersBoard(std::string zz, std::string yy);
        void simple_move(CheckersSimpleMove ty);
        CheckersPiece & operator[](CheckersPosition d);
        void move(CheckersMove ds);
        int winner();
        int validate(CheckersMove ht);
        CheckersPiece & board_get_piece_at(int row, int col);
};
CheckersPiece get_piece_at(CheckersBoard aw, int row, int col);
std::ostream& operator<<(std::ostream & rd, CheckersBoard asd);



#endif  // __CHECKERSBOARD_H__