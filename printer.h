/**
* printer: Converts the tree to a type that can be printed
* @author Micha Veldhuijzen (s1513168)
* @file printer.h
* @date 22-17-2017
**/

#ifndef printer_h
#define printer_h

#include <vector>
#include "node.h"
#include "valid.h"

using namespace std;

class Printer {
public:
    Printer();
    ~Printer();

    /**
    * @function printTreeInOrder
    * @abstract calls parseNode to receive a stringstream of the tree in in-order notation
    * @param tree is the expression to be converted to in-order notation
    * @return results in a string of the expression in in-order notation
    **/
    string printTreeInOrder(vector<Node> tree);

    /**
    * @function printTreeInDOT
    * @abstract calls convertToDOT and writes the result to a file
    * @param tree is the expression to be converted to DOT notation
    * @param fileName is the name of the file where the result is written
    * @return results in a file with the DOT notation
    **/
    void printTreeInDOT(vector<Node> tree, string fileName);

private:

    /**
    * @function parseNode
    * @abstract converts a tree to in-order notation with brackets
    * @param tree is the tree to be converted
    * @param s is the stringstream which contains the converted tree
    * @param parentType is the type of the node of the parent
    * @param isLeftChild is true if the node is the left child of its parent
    * @return changes stringstream until it contains the whole converted tree
    * @pre tree must be in pre-order notation
    **/
    void parseNode(vector<Node> tree, stringstream &s, constants::NodeTypes parentType, bool isLeftChild);

    /**
    * @function isNumber
    * @abstract checks if node is a number
    * @param node is the node to be checked
    * @return true if the node is a number, otherwise false
    **/
    bool isNumber(Node node);

    /**
    * @function isVariable
    * @abstract checks if  node is a variable
    * @param node is the node to be checked
    * @return true if the node is a variable, otherwise false
    **/
    bool isVariable(Node node);

    /**
    * @function isNumberOrVariable
    * @abstract checks if node is a number or variable
    * @param node is the node to be checked
    * @return true if the node is a number or variable, otherwise false
    **/
    bool isNumberOrVariable(Node node);

    /**
    * @function isSinOrCos
    * @abstract checks if node is sin or cos
    * @param node is the node to be checked
    * @return true if the node is sin or cos, otherwise false
    **/
    bool isSinOrCos(Node node);

    /**
    * @function needsBrackets
    * @abstract checks if brackets are required around node child
    * @param parent is the parent node
    * @param child is the child node
    * @param isLeftChild is true if the child is the left child of the parent
    * @return returns true if the operation in child has a lower, or sometimes the same priority as
    *         the operation in parent, or if the parent node is sin or cos
    **/
    bool needsBrackets(constants::NodeTypes parent, constants::NodeTypes child, bool isLeftChild);

    /**
    * @function convertToDot
    * @abstract converts tree to DOT notation
    * @param tree is the tree to be converted
    * @param s is the stringstream which gets changed as the method walks through the tree
    * @return at the end of the function, s contains the DOT notation of the tree
    * @pre tree must be in in-order notation
    **/
    void convertToDOT(vector<Node> tree, stringstream &s);

    Valid *valid;

    int currentIndex;
};

#endif