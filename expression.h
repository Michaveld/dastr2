#ifndef expression_h
#define expression_h

#include "parser.h"
#include "node.h"
#include "printer.h"
#include "valid.h"
#include <vector>

class Expression {
public:
    Expression();
    ~Expression();
    void read(string input);
    string printTree();
    bool isValidExpression();
    void printTreeInDOT(string fileName);

private:
    vector<Node> tree;
    Parser *parser;
    Printer *printer;
    Valid *valid;
};

#endif