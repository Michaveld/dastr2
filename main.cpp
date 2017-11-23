/**
* main: Makes sure the class Menu is executed
* @author Micha Veldhuijzen (s1513168)
* @file main.cpp
* @date 23-17-2017
**/

#include "menu.h"

using namespace std;

int main(int argc, char** argv) {
    bool debugMode;
    if (argc < 2) {
        debugMode = false;
    }
    else {
        if (string(argv[1]) == "d") {
            debugMode = true;
        }
    }
    cout << debugMode << endl;

    Menu *m = new Menu(debugMode);

    string input;
    string firstWord;
    if (!debugMode) {
        m->printMenu();
    }
    getline(cin, input);
    m->seperateInput(input, firstWord);
    m->executeCommand(input, firstWord);

    delete m;

    return 0;
}