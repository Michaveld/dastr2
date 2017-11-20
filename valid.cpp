#include "valid.h"

Valid::~Valid() {

}

Valid::Valid() {

}

bool Valid::isEveryNodeFilled(vector<Node> tree) {
    int emptyNodes = 1;
    vector<Node>::iterator it = tree.begin();
    while (it != tree.end() && emptyNodes != 0) {
        emptyNodes += it->arity - 1;
        it++;
    }
    return it == tree.end() && emptyNodes == 0;
}

bool Valid::arePowersValid(vector<Node> tree) {
    return areExponentsNumbers(tree) && !arePowersConsecutive(tree);
}

bool Valid::areExponentsNumbers(vector<Node> tree) {
    int emptyNodes = 1;
    for (int i = 0; i < tree.size(); i++) {
        emptyNodes += tree[i].arity - 1;
        if (tree[i].type == constants::POWER) {
            int tempI = i + 1;
            int tempEmptyNodes = emptyNodes;
            int wantedEmptyNodes = emptyNodes - 1;
            while (tempEmptyNodes != wantedEmptyNodes) {
                tempEmptyNodes += tree[tempI].arity - 1;
                tempI++;
            }
            if (tree[tempI].type != constants::NUMBER) {
                return false;
            }
        }
    }
    return true;
}

bool Valid::arePowersConsecutive(vector<Node> tree) {
    for (int i = 0; i < tree.size()-1; i++) {
        if (tree[i].type == constants::POWER && tree[i+1].type == constants::POWER) {
            return true;
        }
    }
    return false;
}