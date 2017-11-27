/**
* parser: Reads the input and converts it to a vector of Nodes
* @author Micha Veldhuijzen (s1513168)
* @file parser.h
* @date 22-17-2017
**/

#ifndef parser_h
#define parser_h

#include <vector>
#include <string>
#include <deque>
#include "node.h"
#include "constants.h"

using namespace std;

class Parser {
public:
    Parser();
    ~Parser();

    /**
    * @function parseInput
    * @abstract takes a string input and calls other functions to convert it to a vector<Node>
    * @param input is the input given by the user
    * @return returns a vector<Node>, which is the tree of the expression in pre-order notation
    **/
    vector<Node> parseInput(string input);

    /**
   * @function dequeParseInput
   * @abstract calls parseInput with input and converts the resulting vector to a deque
   * @param input is the expression to be converted to vector and then to deque
   * @return returns the expression in a deque
   **/
    deque<Node> dequeParseInput(string input);

    /**
    * @function isNumber
    * @abstract checks if the string word is a number
    * @param word is the word to be checked
    * @return true if word is a number, otherwise false
    **/
    bool isNumber(const string &word) const;

    /**
    * @function createNode
    * @abstract creates a Node with properties type and arity, and value or oper from word
    * @param word becomes the value of value or oper, depending on its type
    * @param type becomes the type of the Node
    * @param arity becomes the arity of the Node
    * @return returns the Node
    **/
    Node createNode(const string &word, const constants::NodeTypes &type, const int &arity) const;

private:

    /**
    * @function inputToVector
    * @abstract adds the words of the input to a vector
    * @param input is the input given by the user
    * @return return a vector of all the words in input
    **/
    vector<string> inputToVector(const string &input) const;

    /**
    * @function wordsToNodes
    * @abstract calls parseWord for every word in words to convert it to a Node
    * @param words is the vector of strings to be converted to a vector of Nodes
    * @return returns a vector of Nodes
    **/
    vector<Node> wordsToNodes(vector<string> words) const;

    /**
    * @function parseWord
    * @abstract converts a word to a Node
    * @param word is the word to be converted to a Node
    * @return results in a Node
    **/
    Node parseWord(const string &word) const;

    /**
    * @function getNodeTypeFromWord
    * @abstract retrieves the type of Node from a word
    * @param word is used to find the type of Node
    * @return results in the type of Node
    **/
    constants::NodeTypes getNodeTypeFromWord(const string &word) const;

    /**
    * @function getArityFromType
    * @abstract retrieves the arity based on the type of Node
    * @param type is the type of the Node
    * @return returns the arity of the Node
    **/
    int getArityFromType(const constants::NodeTypes &type) const;

    /**
    * @function isVariable
    * @abstract checks if word is a variable
    * @param word is the word to be checked
    * @return true if the word is a variable, otherwise false
    **/
    bool isVariable(const string &word) const;
};

#endif