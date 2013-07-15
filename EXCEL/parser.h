#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <stack>
#include <list>
#include <map>
#include <algorithm>
#include <iostream>
#include <assert.h>
#include "definedtypes.h"
#include "syntaxtree.h"
using namespace std;

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
    list<token> getOutputList(){return outputList;}
};

#endif // PARSER_H

