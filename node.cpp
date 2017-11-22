/**
* node: Overloads the '<<' and '>>' operators of the Node class
* @author Micha Veldhuijzen (s1513168)
* @file node.cpp
* @date 22-17-2017
**/

#include "node.h"

using namespace std;

ostream &operator<<(ostream &os, const Node &node) {
    if (node.type == constants::NUMBER) {
        return os << node.value;
    }
    else {
        return os << node.oper;
    }
}

istream &operator>>(istream &is, Node &node) {
    if (node.type == constants::NUMBER) {
        is >> node.value;
    }
    else {
        is >> node.oper;
    }
    return is;
}