/**
* parser: Reads the input and converts it to a vector of Nodes
* @author Micha Veldhuijzen (s1513168)
* @file parser.cpp
* @date 22-17-2017
**/

#include "parser.h"
#include <sstream>
#include <cstdlib>

using namespace std;

Parser::Parser() {

}

Parser::~Parser() {

}

vector<Node> Parser::parseInput(string input) {
    vector<string> words = inputToVector(input);
    return wordsToNodes(words);
}

deque<Node> Parser::dequeParseInput(string input) {
    vector<Node> tree = parseInput(input);
    deque<Node> temp;
    for (unsigned int i = 0; i < tree.size(); i++) {
        temp.push_back(tree[i]);
    }
    return temp;
}

vector<string> Parser::inputToVector(const string &input) const {
    string line;
    vector<string> words;
    for (stringstream stream(input); stream >> line;)
    {
        words.push_back(line);
    }

    return words;
}

vector<Node> Parser::wordsToNodes(vector<string> words) const {
    vector<Node> nodes;
    for (vector<string>::iterator it = words.begin(); it != words.end(); it++) {
        nodes.push_back(parseWord(*it));
    }

    return nodes;
}

Node Parser::parseWord(const string &word) const {
    constants::NodeTypes type = getNodeTypeFromWord(word);
    int arity = getArityFromType(type);
    Node node = createNode(word, type, arity);
    return node;
}

constants::NodeTypes Parser::getNodeTypeFromWord(const string &word) const {
    if (isNumber(word)) {
        return constants::NUMBER;
    }
    else if (isVariable(word)) {
        return constants::VARIABLE;
    }
    else {
        if (word == "+") {return constants::PLUS;}
        if (word == "-") {return constants::MINUS;}
        if (word == "^") {return constants::POWER;}
        if (word == "*") {return constants::TIMES;}
        if (word == "/") {return constants::DIVISION;}
        if (word == "sin") {return constants::SIN;}
        if (word == "cos") {return constants::COS;}
        if (word == "pi") {return constants::PI;}
        if (word == "delta") {return constants::DELTA;}
    }

    throw invalid_argument("Invalid input: " + word);
}

Node Parser::createNode(const string &word, const constants::NodeTypes &type, const int &arity) const {
    Node node;
    node.type = type;
    node.arity = arity;
    if (type == constants::PI) {
        node.value = 3.14159265;
        node.oper = "pi";
    }
    else if (type == constants::NUMBER) {
        const char* c = word.c_str();
        node.value = atof(c);
    }
    else {
        node.oper = word;
    }

    return node;
}

int Parser::getArityFromType(const constants::NodeTypes &type) const {
    if (type == constants::NUMBER || type == constants::VARIABLE || type == constants::PI) {
        return 0;
    }
    else if (type == constants::SIN || type == constants::COS || type == constants::DELTA) {
        return 1;
    }
    else {
        return 2;
    }
}

bool Parser::isNumber(const string &word) const {
    double number;
    istringstream s(word);
    s >> number;
    return (s.eof() && !s.fail());
}

bool Parser::isVariable(const string &word) const {
    if (word.length() == 1) {
        int i = word.at(0);
        if (i >= 97 && i <= 122) {
            return true;
        }
    }
    return false;
}