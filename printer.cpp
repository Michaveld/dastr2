#include <sstream>
#include "printer.h"

Printer::Printer() : currentIndex(0) {
    cout << "Hallo" << endl;
}

Printer::~Printer() {

}

string Printer::printTreeInOrder(vector<Node> tree) {
    stringstream s;
    currentIndex = 0;
    parseNode(tree, s, constants::ROOT, false);
    return s.str();
}

void Printer::parseNode(vector<Node> tree, stringstream &s, constants::NodeTypes parentType, bool isLeftChild) {
    Node node = tree[currentIndex];
    bool addBrackets = needsBrackets(parentType, node.type, isLeftChild);
    if (addBrackets) {
        s << "(";
    }

    if (isNumberOrVariable(node)) {
        s << node;
    }
    else {
        currentIndex++;
        if (!isSinOrCos(node)) {
            parseNode(tree, s, node.type, true);
            currentIndex++;
        }
        s << node;
        parseNode(tree, s, node.type, false);
    }

    if (addBrackets){
        s << ")";
    }
}

bool Printer::needsBrackets(constants::NodeTypes parent, constants::NodeTypes child, bool isLeftChild) {
    if (parent == constants::ROOT) {
        return false;
    }
    else if (parent == constants::SIN || parent == constants::COS) {
        return true;
    }
    else if (child == constants::PI || child == constants::NUMBER || child == constants::VARIABLE) {
        return false;
    }
    else if (child == constants::POWER) {
        return false;
    }
    else if (parent == constants::POWER) {
        return true;
    }
    else if (child == constants::PLUS || child == constants::MINUS) {
        return parent == constants::TIMES || parent == constants::DIVISION;
    }
    else {
        return parent == constants::DIVISION && !isLeftChild;
    }
}

bool Printer::isNumberOrVariable(Node node) {
    return isNumber(node) || isVariable(node);
}

bool Printer::isNumber(Node node) {
    return node.type == constants::NUMBER || node.type == constants::PI;
}

bool Printer::isVariable(Node node) {
    return node.type == constants::VARIABLE;
}

bool Printer::isSinOrCos(Node node) {
    return node.type == constants::SIN || node.type == constants::COS;
}