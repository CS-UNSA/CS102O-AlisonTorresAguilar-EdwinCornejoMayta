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

using namespace std;

class parser
{

public:
    parser();
    parser(string b):buffer(b){}
    inline  void setBuffer(string b){buffer=b;
    if(buffer[0]=='='){
     buffer=buffer.substr(1,buffer.size());
     content= EXPRESSION;
    }else if(isdigit(buffer[0])){
     content=  NUMERIC;
    }else
     content= TEXT;

    }
    inline  string getBuffer() {return buffer;}
    inline list<token>* getOutputList(){return &outputList;}
    void getTokens();
    void toPostfix();
    contentType getTypeContent();

private:
    string       buffer;
    size         bufferSize;
    list<token>  tokenList;
    list<token>  outputList;
    stack<token> outputStack;
    contentType  content;
    int getPrecedingFunction(string fun);
};

#endif // PARSER_H

