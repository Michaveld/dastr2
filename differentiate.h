/**
* Differentiate: differentiates the expression
* @author Micha Veldhuijzen (s1513168)
* @file differentiate.h
* @date 27-11-2017
**/

#ifndef differentiate_h
#define differentiate_h

#include "parser.h"
#include "valid.h"
#include "printer.h"
#include "node.h"
#include <vector>
#include <deque>

class Differentiate {
public:
    Differentiate();
    ~Differentiate();

    /**
    * @function differentiate
    * @abstract converts tree from vector to deque and calls doDifferentiation
    * @param tree is the tree to be differentiated
    * @return returns the differentiated tree with respect to x
    **/
    vector<Node> differentiate(vector<Node> tree);

private:
    /**
    * @function vectorToDeque
    * @abstract converts a vector to a deque
    * @param tree is the tree that is converted
    * @return returns a deque of tree
    **/
    deque<Node> vectorToDeque(vector<Node> tree);

    /**
    * @function doDifferentiation
    * @abstract continually finds the first delta and calls the right differentiate function
    * @param tree is the tree to be differentiated
    * @return returns the differentiated tree
    * @post all deltas are gone at the end of the function
    **/
    deque<Node> doDifferentiation(deque<Node> tree);

    /**
    * @function differentiatePlusMinus
    * @abstract differentiates the subtree of tree after delta, with plus or minus as its root
    * @param tree is the tree which includes the subtree that will be differentiated
    * @param index is the index of the node with delta in it
    * @return replaces (a subtree of) tree with the differentiated (sub)tree
    **/
    void differentiatePlusMinus(deque<Node> &tree, int index);

    /**
   * @function differentiateX
   * @abstract called if the child of delta is x. Differentiates x, which is 1
   * @param tree is the tree which includes the subtree that will be differentiated
   * @param index is the index of the node with delta in it
   * @return replaces the subtree with 1
   **/
    void differentiateX(deque<Node> &tree, int index);

    /**
   * @function differentiateNumber
   * @abstract called if the child of delta is a number. Differentiates the number, which is 0
   * @param tree is the tree which includes the subtree that will be differentiated
   * @param index is the index of the node with delta in it
   * @return replaces the subtree with 0
   **/
    void differentiateNumber(deque<Node> &tree, int index);

    /**
   * @function differentiatePower
   * @abstract differentiates the subtree of tree after delta, with power as its root
   * @param tree is the tree which includes the subtree that will be differentiated
   * @param index is the index of the node with delta in it
   * @return replaces (a subtree of) tree with the differentiated (sub)tree
   **/
    void differentiatePower(deque<Node> &tree, int index);

    /**
   * @function differentiateTimes
   * @abstract differentiates the subtree of tree after delta, with times as its root
   * @param tree is the tree which includes the subtree that will be differentiated
   * @param index is the index of the node with delta in it
   * @return replaces (a subtree of) tree with the differentiated (sub)tree
   **/
    void differentiateTimes(deque<Node> &tree, int index);

    /**
   * @function differentiateDivision
   * @abstract differentiates the subtree of tree after delta, with division as its root
   * @param tree is the tree which includes the subtree that will be differentiated
   * @param index is the index of the node with delta in it
   * @return replaces (a subtree of) tree with the differentiated (sub)tree
   **/
    void differentiateDivision(deque<Node> &tree, int index);

    /**
   * @function differentiateSinCos
   * @abstract differentiates the subtree of tree after delta, with sin or cos as its root
   * @param tree is the tree which includes the subtree that will be differentiated
   * @param index is the index of the node with delta in it
   * @return replaces (a subtree of) tree with the differentiated (sub)tree
   **/
    void differentiateSinCos(deque<Node> &tree, int index);

    /**
   * @function subtreeToString
   * @abstract converts a subtree to a string
   * @param tree is the tree which includes the subtree that will be converted
   * @param index is the index of the root of the subtree
   * @return returns a string representation of the subtree
   **/
    string subtreeToString(deque<Node> tree, int index);

    /**
   * @function lastIndexSubTree
   * @abstract finds the index of the last element of a subtree
   * @param tree is the tree which includes the subtree of which the last element will be found
   * @param index is the index of the root of the subtree
   * @return returns the index of the last node of the subtree
   **/
    int lastIndexSubTree(deque<Node> tree, int index);

    Valid *v;
    Parser *p;
};


#endif
