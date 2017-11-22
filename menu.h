/**
* menu: Prints the menu and make sure the right methods in expression.cpp are called
* @author Micha Veldhuijzen (s1513168)
* @file menu.h
* @date 22-17-2017
**/

#ifndef menu_h
#define menu_h

#include <string>
#include "expression.h"

using namespace std;

class Menu {
public:
    Menu(bool _debugMode);
    ~Menu();

    /**
    * @function printMenu
    * @abstract prints the menu
    **/
    void printMenu();

    /**
    * @function seperateInput
    * @abstract separates the first word of the input (the command) from the rest
    * @param input is the input given by the user
    * @param firstWord becomes the first word of the input
    * @return the first word of input gets removed and put in firstWord
    **/
    void seperateInput(string &input, string &firstWord);

    /**
    * @function executeCommand
    * @abstract makes sure the command from the user gets executed
    * @param input is the input from the user (with the first word removed)
    * @param firstWord is the first word of the input that was removed
    * @return executes the users commands as long as the command is not 'end'
    **/
    void executeCommand(string input, string firstWord);
private:
    Expression *e;
    bool debugMode;
};

#endif