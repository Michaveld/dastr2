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
            int tempI = findIndexRightChild(i, tree);
            if (tree[tempI].type != constants::NUMBER && tree[tempI].type != constants::PI) {
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

int Valid::findIndexRightChild(int indexParent, vector<Node> tree) {
    if (tree[indexParent].arity == 0) {
        return 0;
    }
    int i = 0;
    int emptyNodes = 1;
    int wantedEmptyNodes = -1;
    while (emptyNodes != wantedEmptyNodes && i < tree.size()) {
        if (i == indexParent) {
            wantedEmptyNodes = emptyNodes;
        }
        emptyNodes += tree[i].arity - 1;
        i++;
    }
    return i;
}