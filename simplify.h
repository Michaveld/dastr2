/**
* simplify: simplifies the expression
* @author Micha Veldhuijzen (s1513168)
* @file simplify.h
* @date 23-11-2017
**/

#ifndef simplify_h
#define simplify_h

#include <vector>
#include "valid.h"
#include "node.h"

using namespace std;

class Simplify {
public:
    Simplify();
    ~Simplify();

    /**
   * @function propertiesZeroOneAndVariables
   * @abstract checks to see if the special properties of zero, one and variables can be used to simplify the tree
   * @param tree is the expression in which the special properties are checked
   * @return returns true if something in the tree has changed, otherwise false
   **/
    bool propertiesZeroOneAndVariables(vector<Node> &tree);

    /**
   * @function simplifyExpression
   * @abstract recursively checks if an operator has only numbers as children. If so it calls simplifySubTree
   * @param tree is the tree which is checked
   * @param index is the index of the current node that is checked
   * @return returns true if anything in the tree has been changed
   **/
    bool simplifyExpression(vector<Node> &tree, int index);

    /**
   * @function eraseNodes
   * @abstract erases the nodes that are left when a calculation was performed
   * @param tree is the tree in which nodes are deleted
   **/
    void eraseNodes(vector<Node> &tree);

    /**
   * @function performSimplification
   * @abstract calls propertiesZeroOneAndVariables and simplifyExpression
   *           until the tree is simplified as mush as possible
   * @param tree is the tree to be simplified
   * @return results in a simplified tree
   **/
    void performSimplification(vector<Node> &tree);

private:
    /**
   * @function simplifySubTree
   * @abstract simplifies a subtree of tree
   * @param tree is the tree that contains the subtree
   * @param index is the index of the root of the subtree
   * @param indexRightChild is the index of the right child of the root
   * @return replaces a subtree of tree with a number
   * @pre the subtree is an operator with one or two numbers as children
   **/
    void simplifySubTree(vector<Node> &tree, int index, int indexRightChild);

    /**
   * @function changeNodeToResult
   * @abstract changes a node to result
   * @param node is the node in the tree that is changed to result
   * @param result is the value to which node is changed
   * @return results in node being changed
   **/
    void changeNodeToResult(Node &node, double result);

    /**
   * @function computeSubTree
   * @abstract calculates the result of a subtree
   * @param parentType is the type of the root of the subtree
   * @param valueLeftChild is the value of the left child of parent
   * @param valueRightChild is the value of the right child of parent
   * @return returns the result
   * @pre the subtree is an operator with one or two numbers as children
   **/
    double computeSubTree(constants::NodeTypes parentType, double valueLeftChild, double valueRightChild);

    /**
   * @function sortVector
   * @abstract sorts vector vec in descending order
   * @param vec is the vector which will be sorted
   * @return results in a sorted vector in descending order
   * @pre the vector must be filled with ints
   **/
    void sortVector(vector<int> &vec);

    /**
   * @function roundNumber
   * @abstract rounds a number to a certain amount of decimals, given by int decimals
   * @param result is the result to be rounded
   * @param decimals is the number of decimals to which result will be rounded
   * @return returns a rounded result
   **/
    double roundNumber(double result, int decimals);

    /**
   * @function deleteSubTree
   * @abstract deletes a subtree, with the exception of the root
   * @param tree is the tree that contains the subtree
   * @param index is the index of the root of the subtree
   * @return results in a tree with a number of nodes deleted
   **/
    void deleteSubTree(vector<Node> &tree, int index);

    /**
   * @function checkOperators
   * @abstract calls all check<operator> functions
   * @param tree is the tree containing an expression
   * @param indexParent is the index of the root of the subtree which is checked
   * @param indexRightChild is the index of the right child of the root
   * @return returns true if the subtree could be replaced by a number, otherwise false
   * @pre the root of the subtree is an operator
   **/
    bool checkOperators(vector<Node> &tree, int indexParent, int indexRightChild);

    /**
   * @function checkPlus
   * @abstract checks if the root of the subtree in tree is plus,
   *           and if its children are numbers, calculates the sum
   * @param tree is the tree containing the subtree
   * @param indexParent is the index of the root of the subtree
   * @param indexRightChild is the index of the right child of the root
   * @return returns true if the subtree could be replaced by a number, otherwise false
   * @pre the root of the subtree is an operator
   **/
    bool checkPlus(vector<Node> &tree, int indexParent, int indexRightChild);

    /**
   * @function checkMinus
   * @abstract checks if the root of the subtree in tree is plus,
   *           and if its children are numbers, calculates the difference
   * @param tree is the tree containing the subtree
   * @param indexParent is the index of the root of the subtree
   * @param indexRightChild is the index of the right child of the root
   * @return returns true if the subtree could be replaced by a number, otherwise false
   * @pre the root of the subtree is an operator
   **/
    bool checkMinus(vector<Node> &tree, int indexParent, int indexRightChild);

    /**
   * @function checkTimes
   * @abstract checks if the root of the subtree in tree is times,
   *           and if its children are numbers, calculates the product
   * @param tree is the tree containing the subtree
   * @param indexParent is the index of the root of the subtree
   * @param indexRightChild is the index of the right child of the root
   * @return returns true if the subtree could be replaced by a number, otherwise false
   * @pre the root of the subtree is an operator
   **/
    bool checkTimes(vector<Node> &tree, int indexParent, int indexRightChild);

    /**
   * @function checkDivision
   * @abstract checks if the root of the subtree in tree is division,
   *           and if its children are numbers, calculates the quotient
   * @param tree is the tree containing the subtree
   * @param indexParent is the index of the root of the subtree
   * @param indexRightChild is the index of the right child of the root
   * @return returns true if the subtree could be replaced by a number, otherwise false
   * @pre the root of the subtree is an operator
   **/
    bool checkDivision(vector<Node> &tree, int indexParent, int indexRightChild);

    /**
   * @function checkPower
   * @abstract checks if the root of the subtree in tree is power,
   *           and if its children are numbers, calculates the power
   * @param tree is the tree containing the subtree
   * @param indexParent is the index of the root of the subtree
   * @param indexRightChild is the index of the right child of the root
   * @return returns true if the subtree could be replaced by a number, otherwise false
   * @pre the root of the subtree is an operator
   **/
    bool checkPower(vector<Node> &tree, int indexParent, int indexRightChild);

    Valid *valid;
    vector<int> nodesToBeDeleted;
};


#endif
