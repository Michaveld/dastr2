#ifndef parser_h
#define parser_h

#include <vector>
#include <string>
#include "node.h"
#include "constants.h"

using namespace std;

class Parser {
public:
    Parser();
    ~Parser();
    vector<Node> parseInput(string input);
private:
    vector<string> inputToVector(const string &input) const;
    vector<Node> wordsToNodes(vector<string> words) const;
    Node parseWord(const string &word) const;
    constants::NodeTypes getNodeTypeFromWord(const string &word) const;
    Node createNode(const string &word, const constants::NodeTypes &type, const int &arity) const;
    int getArityFromType(const constants::NodeTypes &type) const;
    bool isNumber(const string &word) const;
    bool isVariable(const string &word) const;
};

#endif