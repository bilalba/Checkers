#ifndef __CHECKERSMOVE_H__
#define __CHECKERSMOVE_H__
  #include <vector>
  #include "CheckersSimpleMove.h"
  class CheckersMove {
    private:
    std::vector<CheckersSimpleMove> simple_moves = 
    std::vector<CheckersSimpleMove>(0);
    public:
    std::vector<CheckersSimpleMove> & get_simple_moves();
    CheckersMove(std::string rt);
};


//  void board_move(CheckersBoard & sdf, CheckersMove er);
//  void board_capt(CheckersBoard & sdf, int row, int col);
//  void board_move_and_capture(CheckersBoard & sdf, CheckersMove er);


#endif  // __CHECKERSMOVE_H__
 