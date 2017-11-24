/**
* simplify: simplifies the expression
* @author Micha Veldhuijzen (s1513168)
* @file simplify.cpp
* @date 23-11-2017
**/

#include "simplify.h"
#include <cmath>
#include <algorithm>

using namespace std;

Simplify::Simplify() {
    valid = new Valid();
}

Simplify::~Simplify() {
    delete valid;
}

bool Simplify::simplifyExpression(vector<Node> &tree, int index) {
    if (tree[index].arity == 0) {
        if (tree[index].type == constants::VARIABLE) {
            return false;
        }
        else if (tree[index].type == constants::NUMBER || tree[index].type == constants::PI) {
            return true;
        }
    }
    else {
        int indexRightChild = valid->findIndexRightChild(index, tree);
        if (tree[index].arity == 2) {
            if (simplifyExpression(tree, index+1) && simplifyExpression(tree, indexRightChild)) {
                simplifySubTree(tree, index, indexRightChild);
                return true;
            }
        }
        else if (tree[index].arity == 1) {
            if (simplifyExpression(tree, index + 1)) {
                simplifySubTree(tree, index, index + 1);
                return true;
            }
        }
        return false;
    }
}

void Simplify::eraseNodes(vector<Node> &tree) {
    sortVector(nodesToBeDeleted);
    for (vector<int>::iterator it = nodesToBeDeleted.begin(); it != nodesToBeDeleted.end(); it++) {
        tree.erase(tree.begin() + *it);
    }
}

void Simplify::simplifySubTree(vector<Node> &tree, int index, int indexRightChild) {
    double result;
    result = computeSubTree(tree[index].type, tree[index + 1].value, tree[indexRightChild].value);
    nodesToBeDeleted.push_back(index + 1);
    if (tree[index].arity != 1) {
        nodesToBeDeleted.push_back(indexRightChild);
    }
    changeNodeToResult(tree[index], result);
}

void Simplify::changeNodeToResult(Node &node, double result) {
    node.type = constants::NUMBER;
    node.arity = 0;
    node.value = result;
    node.oper.clear();
}

double Simplify::computeSubTree(constants::NodeTypes parentType, double valueLeftChild, double valueRightChild) {
    double result;
    if (parentType == constants::SIN) {
        result = sin(valueRightChild);
    }
    else if (parentType == constants::COS) {
        result = cos(valueRightChild);
    }
    else {
        int i = parentType;
        switch (i) {
            case 0:
                result = valueLeftChild + valueRightChild;
                break;
            case 1:
                result = valueLeftChild - valueRightChild;
                break;
            case 4:
                result = pow(valueLeftChild, valueRightChild);
                break;
            case 5:
                result = valueLeftChild * valueRightChild;
                break;
            case 6:
                result = valueLeftChild / valueRightChild;
                break;
            default:
                cout << "Unable to compute" << endl;
                break;
        }
    }
    result = roundNumber(result, 4);
    return result;
}

void Simplify::sortVector(vector<int> &vec) {
    sort(vec.begin(), vec.end(), std::greater<int>());
}

double Simplify::roundNumber(double result, int decimals) {
    return round(result * pow(10, decimals)) / pow(10, decimals);
}