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

    bool propertiesZeroOneAndVariables(vector<Node> &tree);
    bool simplifyExpression(vector<Node> &tree, int index);
    void eraseNodes(vector<Node> &tree);
    void performSimplification(vector<Node> &tree);

private:
    void simplifySubTree(vector<Node> &tree, int index, int indexRightChild);
    void changeNodeToResult(Node &node, double result);
    double computeSubTree(constants::NodeTypes parentType, double valueLeftChild, double valueRightChild);
    void sortVector(vector<int> &vec);
    double roundNumber(double result, int decimals);
    void deleteSubTree(vector<Node> &tree, int index);
    bool checkOperators(vector<Node> &tree, int indexParent, int indexRightChild);
    bool checkPlus(vector<Node> &tree, int indexParent, int indexRightChild);
    bool checkMinus(vector<Node> &tree, int indexParent, int indexRightChild);
    bool checkTimes(vector<Node> &tree, int indexParent, int indexRightChild);
    bool checkDivision(vector<Node> &tree, int indexParent, int indexRightChild);
    bool checkPower(vector<Node> &tree, int indexParent, int indexRightChild);

    Valid *valid;
    vector<int> nodesToBeDeleted;
};


#endif
