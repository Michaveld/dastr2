/**
* expression: Calls the relevant methods to execute the commands
* @author Micha Veldhuijzen (s1513168)
* @file expression.cpp
* @date 23-11-2017
**/

#include "expression.h"

using namespace std;

Expression::Expression() {
    parser = new Parser();
    printer = new Printer();
    valid = new Valid();
    simplify = new Simplify();
}

Expression::~Expression() {
    delete parser;
    delete printer;
    delete valid;
    delete simplify;
}

void Expression::read(string input) {
    tree = parser->parseInput(input);
}

string Expression::printTree() {
    if (tree.empty()) {
        return "No expression found";
    }
    return printer->printTreeInOrder(tree);
}

bool Expression::isValidExpression() {
    if (valid->arePowersValid(tree) && valid->isEveryNodeFilled(tree)) {
        return true;
    }
    clearTree();
    return false;
}

void Expression::printTreeInDOT(string fileName) {
    if (tree.empty()) {
        cout << "No expression found" << endl;
        return;
    }
    printer->printTreeInDOT(tree, fileName);
}

void Expression::clearTree() {
    tree.clear();
}

void Expression::simplifyTree() {
    if (tree.empty()) {
        cout << "No expression found" << endl;
        return;
    }
    simplify->simplifyExpression(tree, 0);
    simplify->eraseNodes(tree);
}
