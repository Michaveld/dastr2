/**
* menu: Prints the menu and makes sure the right methods in expression.cpp are called
* @author Micha Veldhuijzen (s1513168)
* @file menu.cpp
* @date 22-17-2017
**/

#include "menu.h"

using namespace std;

Menu::Menu() {
    e = new Expression();
}

Menu::~Menu() {
    delete e;
}

void Menu::printMenu() {
    cout << "Wat wilt u doen?\n";
    cout << "exp <expressie>: een expressie invoeren\n";
    cout << "print: de opgeslagen boom printen in in-fix notatie\n";
    cout << "dot <bestandsnaam>: de boom opslaan in DOT notatie in een bestand\n";
    cout << "end: het programma afsluiten\n";
}

void Menu::seperateInput(string &input, string &firstWord) {
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
        else {
            cout << "Wrong input, try again:\n";
        }
        printMenu();
        getline(cin, input);
        seperateInput(input, firstWord);
    }
}

