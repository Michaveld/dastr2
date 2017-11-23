/**
* evaluate: replaces x with a value given by the user
* @author Micha Veldhuijzen (s1513168)
* @file evaluate.h
* @date 23-11-2017
**/

#ifndef evaluate
#define evaluate

#include <vector>
#include "node.h"
#include "simplify.h"

using namespace std;

class Evaluate {
public:
    Evaluate();
    ~Evaluate();
    void evaluateExpression(vector<Node> &tree, double value);
private:
    Simplify *s;
};

#endif
