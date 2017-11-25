/**
* menu: Prints the menu and makes sure the right methods in expression.cpp are called
* @author Micha Veldhuijzen (s1513168)
* @file menu.cpp
* @date 23-17-2017
**/

#include <cstdlib>
#include "menu.h"

using namespace std;

Menu::Menu(bool _debugMode) : debugMode(_debugMode) {
    e = new Expression();
    p = new Parser();
}

Menu::~Menu() {
    delete e;
    delete p;
}

void Menu::printMenu() {
    cout << "Wat wilt u doen?\n";
    cout << "exp <expressie>: een expressie invoeren.\n";
    cout << "print: de opgeslagen boom printen in in-fix notatie.\n";
    cout << "dot <bestandsnaam>: de boom opslaan in DOT notatie in een bestand.\n";
    cout << "simp: de boom vereenvoudigen.\n";
    cout << "eval: de boom evalueren met een bepaalde waarde voor x. Voert daarna meteen simp uit.\n";
    cout << "diff: de boom differencieren naar x toe.\n";
    cout << "end: het programma afsluiten.\n";
}

void Menu::separateInput(string &input, string &firstWord) {
    firstWord = input.substr(0, input.find(' '));
    input = input.substr(input.find(' ') + 1);
}

void Menu::executeCommand(string input, string firstWord) {
    while (firstWord != "end") {
        if (firstWord == "exp") {
            e->read(input);
            if (!e->isValidExpression()) {
                cout << "Invalid expression" << endl;
            }
        }
        else if (firstWord == "print") {
            cout << e->printTree() << endl;
        }
        else if (firstWord == "dot") {
            e->printTreeInDOT(input);
        }
        else if (firstWord == "simp") {
            e->simplifyTree();
        }
        else if (firstWord == "eval") {
            if (p->isNumber(input)) {
                const char *c = input.c_str();
                e->evaluateTree(atof(c));
            }
            else {
                cout << "Input is not a number" << endl;
            }
        }
        else if (firstWord == "diff") {
            e->differentiateTree();
        }
        else {
            cout << "Wrong input, try again:\n";
        }
        if (!debugMode) {
            printMenu();
        }
        getline(cin, input);
        separateInput(input, firstWord);
    }
}

