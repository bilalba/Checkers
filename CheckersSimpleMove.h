#ifndef __CHECKERSSIMPLEMOVE_H__
#define __CHECKERSSIMPLEMOVE_H__
#include <vector>
#include "CheckersPiece.h"


class CheckersSimpleMove {
    private:
    CheckersPosition start;
    CheckersPosition end;
    public:
    CheckersSimpleMove(std::string zt, std::string rt);
    CheckersSimpleMove();
    void set_start(CheckersPosition tf);
    void set_end(CheckersPosition tf);
    CheckersPosition get_start();
    CheckersPosition get_end();
};




#endif  // __CHECKERSSIMPLEMOVE_H__
  