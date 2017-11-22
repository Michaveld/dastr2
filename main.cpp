/**
* main: Makes sure the class Menu is executed
* @author Micha Veldhuijzen (s1513168)
* @file main.cpp
* @date 22-17-2017
**/

#include "menu.h"

using namespace std;

int main() {
    Menu *m = new Menu();

    string input;
    string firstWord;
    m->printMenu();
    getline(cin, input);
    m->seperateInput(input, firstWord);
    m->executeCommand(input, firstWord);

    delete m;
    return 0;
}