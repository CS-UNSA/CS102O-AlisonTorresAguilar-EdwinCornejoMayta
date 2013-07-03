#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <stack>
#include <list>
#include <map>
#include <algorithm>
#include <iostream>
#include "node.h"
#include "syntaxtree.h"
#include "definedtypes.h"

using namespace std;

enum tokenType{ NUMBER, VARIABLE, LPARENTHESIS, RPARENTHESIS, OPERATOR, FUNCTION, NONE, EXPRESSION};

struct token{
    string value;
    tokenType type;
};

class parser
{
public:
    parser();
    string buffer;
    unsigned int bufferSize;
    list<token> tokenList;
    // to postfix
    list<token>  outputList;
    stack<token> outputStack;


    void getTokens();
    void toPostfix();
    inline  void setBuffer(string b){buffer=b;}
    inline  string getBuffer() {return buffer;}
    int getPrecedingFunction(string fun);
    void toBinaryTree();

};

#endif // PARSER_H

