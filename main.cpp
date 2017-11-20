#include "expression.h"

using namespace std;

int main() {
    string input;
    getline(cin, input);

    Expression *e = new Expression();
    e->read(input);
    while (!e->isValidExpression()) {
        cout << "Invalid expression" << endl;
        getline(cin, input);
        e->read(input);
    }
    cout << e->printTree() << endl;

    delete e;
    return 0;
}