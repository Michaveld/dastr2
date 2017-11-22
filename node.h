/**
* node: Overloads the '<<' and '>>' operators of the Node class
* @author Micha Veldhuijzen (s1513168)
* @file node.h
* @date 22-17-2017
**/

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

ostream &operator<<(ostream &os, const Node &node);
istream &operator>>(istream &is, const Node &node);
#endif