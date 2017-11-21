#include "expression.h"

using namespace std;

Expression::Expression() {
    parser = new Parser();
    printer = new Printer();
    valid = new Valid();
}

Expression::~Expression() {
    delete parser;
    delete printer;
    delete valid;
}

void Expression::read(string input) {
    tree = parser->parseInput(input);
}

string Expression::printTree() {
    return printer->printTreeInOrder(tree);
}

void Expression::printTreeInDOT(string fileName) {
    printer->printTreeInDOT(tree, fileName);
}

bool Expression::isValidExpression() {
    return valid->arePowersValid(tree) && valid->isEveryNodeFilled(tree);
}