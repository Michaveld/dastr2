#ifndef differentiate_h
#define differentiate_h

#include "node.h"
#include "parser.h"
#include "valid.h"
#include "printer.h"
#include <vector>
#include <deque>

class Differentiate {
public:
    Differentiate();
    ~Differentiate();

    vector<Node> differentiate(vector<Node> tree);

private:
    deque<Node> vectorToDeque(vector<Node> tree);
    deque<Node> doDifferentiation(deque<Node> tree);
    void differentiatePlusMinus(deque<Node> &tree, int index);
    void differentiateX(deque<Node> &tree, int index);
    void differentiateNumber(deque<Node> &tree, int index);
    void differentiatePower(deque<Node> &tree, int index);
    void differentiateTimes(deque<Node> &tree, int index);
    void differentiateDivision(deque<Node> &tree, int index);
    void differentiateSinCos(deque<Node> &tree, int index);
    string subtreeToStringstream(deque<Node> tree, int index);
    int lastIndexSubTree(deque<Node> tree, int index);

    Valid *v;
    Parser *p;
};


#endif
