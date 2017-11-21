#ifndef valid_h
#define valid_h

#include <vector>
#include "node.h"

class Valid {
public:
    Valid();
    ~Valid();
    bool isEveryNodeFilled(vector<Node> tree);
    bool arePowersValid(vector<Node> tree);
    int findIndexRightChild(int indexParent, vector<Node> tree);

private:

    bool areExponentsNumbers(vector<Node> tree);

    bool arePowersConsecutive(vector<Node> tree);
};


#endif
