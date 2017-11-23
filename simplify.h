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

// TODO: add special properties of 1 and 2, x/x = 1 and x-x = 0

class Simplify {
public:
    Simplify();
    ~Simplify();

    bool simplifyExpression(vector<Node> &tree, int index);
    void eraseNodes(vector<Node> &tree);

private:
    void simplifySubTree(vector<Node> &tree, int index, int indexRightChild);
    void changeNodeToResult(Node &node, double result);
    double computeSubTree(constants::NodeTypes parentType, double valueLeftChild, double valueRightChild);
    void sortVector(vector<int> &vec);

    Valid *valid;
    vector<int> nodesToBeDeleted;
};


#endif
