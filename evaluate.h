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

    /**
   * @function evaluateExpression
   * @abstract replaces all appearences of x with value
   * @param tree is the tree in which all x's are replaced
   * @param value is what all x's will be replaced with
   * @return edits the tree during the function
   * @post no x's remain in the tree
   **/
    void evaluateExpression(vector<Node> &tree, double value);
private:
    Simplify *s;
};

#endif
