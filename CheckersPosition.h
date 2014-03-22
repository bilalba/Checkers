#ifndef __CHECKERSPOSITION_H__
#define __CHECKERSPOSITION_H__
#include <vector>
#include <string>
class CheckersPosition {
        private:
        int row;
        int col;
        public:
        int get_row();
        int get_col();
        void set_row(int d);
        void set_col(int s);
        CheckersPosition(std::string tr);
        CheckersPosition(int s, int f);
        CheckersPosition();
        bool operator==(CheckersPosition d);
};

CheckersPosition position_parse(std::string b); 




#endif  // __CHECKERSPOSITION_H__
 