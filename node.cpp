#include "node.h"

using namespace std;

ostream &operator<<(ostream &s, const Node &node) {
    if (node.type == constants::NUMBER) {
        return s << node.value;
    }
    else {
        return s << node.oper;
    }
}