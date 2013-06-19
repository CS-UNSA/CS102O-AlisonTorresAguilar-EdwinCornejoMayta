#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <stack>
#include <list>
#include <map>
#include <algorithm>
#include <iostream>
#include "definedtypes.h"
using namespace std;

enum tokenType{ NUMBER, VARIABLE, LPARENTHESIS, RPARENTHESIS, OPERATOR, FUNCTION, NONE};



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

    void getTokens();
    void toPostfix();
    inline  void setBuffer(string b){buffer=b;}
    inline  string getBuffer() {return buffer;}
    int getPrecedingFunction(string fun);

};

#endif // PARSER_H
