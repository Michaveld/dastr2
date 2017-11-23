/**
* evaluate: replaces x with a value given by the user
* @author Micha Veldhuijzen (s1513168)
* @file evaluate.cpp
* @date 23-11-2017
**/

#include "evaluate.h"

Evaluate::Evaluate() {
    s = new Simplify();
}

Evaluate::~Evaluate() {
    delete s;
}

void Evaluate::evaluateExpression(vector<Node> &tree, double value) {
    for (unsigned int i = 0; i < tree.size(); i++) {
        if (tree[i].type == constants::VARIABLE && tree[i].oper == "x") {
            tree[i].type = constants::NUMBER;
            tree[i].value = value;
            tree[i].oper.clear();
        }
    }
    s->simplifyExpression(tree, 0);
    s->eraseNodes(tree);
}
