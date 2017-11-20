#ifndef node_h
#define node_h

#include <string>
#include <iostream>
#include "constants.h"

using namespace std;

struct Node {
    constants::NodeTypes type;
    double value;
    string oper;
    int arity;
};

ostream &operator<<(ostream &s, const Node &node);
#endif