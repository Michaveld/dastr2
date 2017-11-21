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