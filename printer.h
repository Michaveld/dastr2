#ifndef printer_h
#define printer_h

#include <vector>
#include "node.h"

using namespace std;

class Printer {
public:
    Printer();
    ~Printer();
    string printTreeInOrder(vector<Node> tree);
private:

    void parseNode(vector<Node> tree, stringstream &s, constants::NodeTypes parentType, bool isLeftChild);

    bool isNumber(Node node);

    bool isVariable(Node node);

    bool isNumberOrVariable(Node node);

    bool isSinOrCos(Node node);

    int currentIndex;

    bool needsBrackets(constants::NodeTypes parent, constants::NodeTypes child, bool isLeftChild);
};

#endif