/**
* constants: Defines the enum NodeTypes, with all possible types of node
* @author Micha Veldhuijzen (s1513168)
* @file constants.h
* @date 19-11-2017
**/

#ifndef constants_h
#define constants_h

#include <map>

using namespace std;

namespace constants {
    enum NodeTypes {
        PLUS, MINUS, NUMBER, VARIABLE, POWER, TIMES, DIVISION, SIN, COS, PI, ROOT
    };
}
#endif