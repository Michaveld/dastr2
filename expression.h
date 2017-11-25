/**
* expression: Calls the relevant methods to execute the commands
* @author Micha Veldhuijzen (s1513168)
* @file expression.h
* @date 23-17-2017
**/

#ifndef expression_h
#define expression_h

#include "parser.h"
#include "printer.h"
#include "valid.h"
#include "simplify.h"
#include "node.h"
#include "evaluate.h"
#include "differentiate.h"
#include <vector>

class Expression {
public:
    Expression();
    ~Expression();

    /**
    * @function read
    * @abstract Calls parser to convert the input to vector<Node> and equals tree to the output
    * @param input is the expression to be converted
    * @return results in filling tree with the expression
    **/
    void read(string input);

    /**
    * @function printTree
    * @abstract if tree is not empty, calls printer to convert tree to a printable type
    * @return results in a printable expression
    * @pre tree must not be empty
    **/
    string printTree();

    /**
    * @function isValidExpression
    * @abstract checks if the tree is valid, otherwise deletes it
    * @return if the expression in tree is not valid, empties tree
    **/
    bool isValidExpression();

    /**
    * @function printTreeInDOT
    * @abstract calls printer to convert tree to DOT notation
    * @param fileName is the name of the file to which the DOT notation should be printed
    * @return results in a file with DOT notation of the expression
    * @pre tree must not be empty
    **/
    void printTreeInDOT(string fileName);

    void simplifyTree();

    void evaluateTree(double value);

    void differentiateTree();

private:

    /**
    * @function clearTree
    * @abstract empties tree
    * @return results in an empty tree
    **/
    void clearTree();
    vector<Node> tree;
    Parser *parser;
    Printer *printer;
    Valid *valid;
    Simplify *simplify;
    Evaluate *eval;
    Differentiate *differentiate;
};

#endif