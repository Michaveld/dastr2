/**
* valid: Checks if the input is a valid expression
* @author Micha Veldhuijzen (s1513168)
* @file valid.h
* @date 22-17-2017
**/

#ifndef valid_h
#define valid_h

#include <vector>
#include "node.h"

class Valid {
public:
    Valid();
    ~Valid();

    /**
    * @function isEveryNodeFilled
    * @abstract checks if every node has the right amount of children
    * @param tree is the tree to be checked
    * @return true if every node has the right amount of children, otherwise false
    **/
    bool isEveryNodeFilled(vector<Node> tree);

    /**
    * @function arePowersValid
    * @abstract checks if all exponents are numbers and if there are no two consecutive powers
    * @param tree is the tree to be checked
    * @return true if all powers are valid, otherwise false
    **/
    bool arePowersValid(vector<Node> tree);

    /**
    * @function findIndexRightChild
    * @abstract finds the index of the right child of a node
    * @param indexParent is the index of the parent whose right child's index is determined
    * @param tree is the tree which contains the parent and child node
    * @return returns the index of the right child, or 0 if there is no child
    **/
    int findIndexRightChild(int indexParent, vector<Node> tree);

private:

    /**
    * @function areExponentsNumbers
    * @abstract checks if all exponents are numbers
    * @param tree is the tree in which the exponents are checked
    * @return returns true if all exponents are numbers, otherwise false
    **/
    bool areExponentsNumbers(vector<Node> tree);

    /**
    * @function arePowersConsecutive
    * @abstract checks if there are consecutive powers
    * @param tree is the tree in which the powers are checked
    * @return true if there are consecutive powers, otherwise false
    **/
    bool arePowersConsecutive(vector<Node> tree);
};


#endif
