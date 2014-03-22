#include "StringUtils.h"
std::vector<std::string> string_split(std::string rtw, char t) {
    unsigned int nom = 0;
    std::vector<std::string> abc(1);
    abc[0] = rtw;
    std::string dz;
    for (char x : rtw) {
        if (x == t) {
           abc.push_back("");
           abc[nom] = dz;
           dz = "";
           nom = nom + 1;
        } else {
            dz = dz + x;
        }   
    }
    abc[nom] = dz;
    return abc;
} 