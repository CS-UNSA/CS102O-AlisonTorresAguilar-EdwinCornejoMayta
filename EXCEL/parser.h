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
//#include "syntaxtree.h"
using namespace std;

class parser
{

public:
    parser();
    parser(string b):buffer(b){}
    inline  void setBuffer(string b){buffer=b;}
    inline  string getBuffer() {return buffer;}
    inline list<token>* getOutputList(){return &outputList;}
    void getTokens();
    void toPostfix();

private:
    string       buffer;
    size         bufferSize;
    list<token>  tokenList;
    list<token>  outputList;
    stack<token> outputStack;
    int getPrecedingFunction(string fun);
};

#endif // PARSER_H

