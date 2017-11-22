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
    if (tree.empty()) {
        return "No expression found";
    }
    return printer->printTreeInOrder(tree);
}

void Expression::printTreeInDOT(string fileName) {
    if (tree.empty()) {
        cout << "No expression found" << endl;
        return;
    }
    printer->printTreeInDOT(tree, fileName);
}

bool Expression::isValidExpression() {
    return valid->arePowersValid(tree) && valid->isEveryNodeFilled(tree);
}

void Expression::clearTree() {
    tree.clear();
}
