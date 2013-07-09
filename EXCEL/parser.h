#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <stack>
#include <list>
#include <map>
#include <algorithm>
#include <iostream>
#include "node.h"
#include "nodenumber.h"
#include "nodecell.h"
#include "nodeoperation.h"
#include <assert.h>
#include "syntaxtree.h"
#include "definedtypes.h"

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

    //to Binary tree
    node *root;


    void getTokens();
    void toPostfix();
    inline  void setBuffer(string b){buffer=b;}
    inline  string getBuffer() {return buffer;}
    int getPrecedingFunction(string fun);
    void toBinaryTree();
    void recorrer();
};

#endif // PARSER_H

