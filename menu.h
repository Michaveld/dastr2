#ifndef menu_h
#define menu_h

#include <string>
#include "expression.h"

using namespace std;

class Menu {
public:
    Menu();
    ~Menu();
    void printMenu();
    void seperateInput(string &input, string &firstWord);
    void executeCommand(string input, string firstWord);
private:
    Expression *e;
};


#endif