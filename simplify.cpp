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

void Simplify::performSimplification(vector<Node> &tree) {
    while (propertiesZeroOneAndVariables(tree) || simplifyExpression(tree, 0)) {
        eraseNodes(tree);
    }
}

bool Simplify::propertiesZeroOneAndVariables(vector<Node> &tree) {
    bool changed = false;
    int i = 0;
    while (i < tree.size()) {
        changed = false;
        if (tree[i].arity == 2) {
            int indexRightChild = valid->findIndexRightChild(i, tree);
            if (checkOperators(tree, i, indexRightChild)) {
                changed = true;
                eraseNodes(tree);
            }
        }
        if (changed) {
            i = 0;
        } else {
            i++;
        }
    }
    return changed;
}

bool Simplify::simplifyExpression(vector<Node> &tree, int index) {
    if (tree[index].arity == 0) {
        if (tree[index].type == constants::VARIABLE) {
            return false;
        }
        else if (tree[index].type == constants::NUMBER || tree[index].type == constants::PI) {
            return index != 0;
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
    }
    return false;
}

void Simplify::eraseNodes(vector<Node> &tree) {
    sortVector(nodesToBeDeleted);
    for (vector<int>::iterator it = nodesToBeDeleted.begin(); it != nodesToBeDeleted.end(); it++) {
        tree.erase(tree.begin() + *it);
    }
    nodesToBeDeleted.clear();
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
            if (valueRightChild == 0) {
                throw invalid_argument("Division by zero is not defined");
            }
            result = valueLeftChild / valueRightChild;
            break;
        case 7:
            result = sin(valueRightChild);
            break;
        case 8:
            result = cos(valueRightChild);
            break;
        default:
            cout << "Unable to compute" << endl;
            break;
    }
    result = roundNumber(result, 4);
    return result;
}

void Simplify::sortVector(vector<int> &vec) {
    sort(vec.begin(), vec.end(), greater<int>());
}

double Simplify::roundNumber(double result, int decimals) {
    return round(result * pow(10, decimals)) / pow(10, decimals);
}

void Simplify::deleteSubTree(vector<Node> &tree, int index) {
    int indexRightChildParent = tree.size();
    if (index != 0) {
        indexRightChildParent = valid->findIndexRightChild(index - 1, tree);
    }
    for (int i = index + 1; i < indexRightChildParent; i++) {
        nodesToBeDeleted.push_back(i);
    }
    eraseNodes(tree);
}

bool Simplify::checkOperators(vector<Node> &tree, int indexParent, int indexRightChild) {
    if (checkPlus(tree, indexParent, indexRightChild)) {
        return true;
    }
    else if (checkMinus(tree, indexParent, indexRightChild)) {
        return true;
    }
    else if (checkTimes(tree, indexParent, indexRightChild)) {
        return true;
    }
    else if (checkDivision(tree, indexParent, indexRightChild)) {
        return true;
    }
    else if (checkPower(tree, indexParent, indexRightChild)) {
        return true;
    }
    return false;
}

bool Simplify::checkPlus(vector<Node> &tree, int indexParent, int indexRightChild) {
    if (tree[indexParent].type == constants::PLUS) {
        if (tree[indexParent+1].type == constants::NUMBER && tree[indexParent+1].value == 0) {
            nodesToBeDeleted.push_back(indexParent);
            nodesToBeDeleted.push_back(indexParent+1);
            return true;
        }
        else if (tree[indexRightChild].type == constants::NUMBER && tree[indexRightChild].value == 0) {
            nodesToBeDeleted.push_back(indexParent);
            nodesToBeDeleted.push_back(indexRightChild);
            return true;
        }
    }
    return false;
}

bool Simplify::checkMinus(vector<Node> &tree, int indexParent, int indexRightChild) {
    if (tree[indexParent].type == constants::MINUS) {
        if (tree[indexParent+1].type == constants::NUMBER && tree[indexParent+1].value == 0) {
            if (tree[indexRightChild].type == constants::NUMBER || tree[indexRightChild].type == constants::PI) {
                nodesToBeDeleted.push_back(indexParent);
                nodesToBeDeleted.push_back(indexParent+1);
                tree[indexRightChild].value *= -1;
                if (tree[indexRightChild].type == constants::PI) {
                    tree[indexRightChild].type = constants::NUMBER;
                }
                return true;
            }
            else {
                tree[indexParent].type = constants::TIMES;
                tree[indexParent].oper = "*";
                tree[indexParent+1].value = -1;
                return true;
            }
        }
        else if (tree[indexRightChild].type == constants::NUMBER && tree[indexRightChild].value == 0) {
            nodesToBeDeleted.push_back(indexParent);
            nodesToBeDeleted.push_back(indexRightChild);
            return true;
        }
        else if (tree[indexParent+1].type == constants::VARIABLE && tree[indexRightChild].type == constants::VARIABLE) {
            if (tree[indexParent+1].oper == tree[indexRightChild].oper) {
                nodesToBeDeleted.push_back(indexParent+1);
                nodesToBeDeleted.push_back(indexRightChild);
                changeNodeToResult(tree[indexParent], 0);
                return true;
            }
        }
    }
    return false;
}

bool Simplify::checkTimes(vector<Node> &tree, int indexParent, int indexRightChild) {
    if (tree[indexParent].type == constants::TIMES) {
        if ((tree[indexParent+1].type == constants::NUMBER && tree[indexParent+1].value == 0) ||
            (tree[indexRightChild].type == constants::NUMBER && tree[indexRightChild].value == 0)) {
            deleteSubTree(tree, indexParent);
            changeNodeToResult(tree[indexParent], 0);
            return true;
        }
        else if (tree[indexParent+1].type == constants::NUMBER && tree[indexParent+1].value == 1) {
            nodesToBeDeleted.push_back(indexParent);
            nodesToBeDeleted.push_back(indexParent+1);
            return true;
        }
        else if (tree[indexRightChild].type == constants::NUMBER && tree[indexRightChild].value == 1) {
            nodesToBeDeleted.push_back(indexParent);
            nodesToBeDeleted.push_back(indexRightChild);
            return true;
        }
    }
    return false;
}

bool Simplify::checkDivision(vector<Node> &tree, int indexParent, int indexRightChild) {
    if (tree[indexParent].type == constants::DIVISION) {
        if (tree[indexRightChild].type == constants::NUMBER) {
            if (tree[indexRightChild].value == 0) {
                throw invalid_argument("Division by zero is not defined");
            }
            else if (tree[indexRightChild].value == 1) {
                nodesToBeDeleted.push_back(indexParent);
                nodesToBeDeleted.push_back(indexRightChild);
                return true;
            }
        }
        if (tree[indexParent+1].type == constants::NUMBER && tree[indexParent+1].value == 0) {
            deleteSubTree(tree, indexParent);
            changeNodeToResult(tree[indexParent], 0);
            return true;
        }
        if (tree[indexParent+1].type == constants::VARIABLE && tree[indexRightChild].type == constants::VARIABLE) {
            if (tree[indexParent+1].oper == tree[indexRightChild].oper) {
                nodesToBeDeleted.push_back(indexParent+1);
                nodesToBeDeleted.push_back(indexRightChild);
                changeNodeToResult(tree[indexParent], 1);
                return true;
            }
        }
    }
    return false;
}

bool Simplify::checkPower(vector<Node> &tree, int indexParent, int indexRightChild) {
    if (tree[indexParent].type == constants::POWER) {
        if (tree[indexRightChild].type == constants::NUMBER && tree[indexRightChild].value == 0) {
            deleteSubTree(tree, indexParent);
            changeNodeToResult(tree[indexParent], 1);
            return true;
        }
        else if (tree[indexRightChild].type == constants::NUMBER && tree[indexRightChild].value == 1) {
            nodesToBeDeleted.push_back(indexParent);
            nodesToBeDeleted.push_back(indexRightChild);
            return true;
        }
    }
    return false;
}
