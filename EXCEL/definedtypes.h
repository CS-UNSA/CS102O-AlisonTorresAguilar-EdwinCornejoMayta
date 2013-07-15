#ifndef DEFINEDTYPES_H
#define DEFINEDTYPES_H

#include <string>
#include <map>
#include <stack>
#include <list>
#include <sstream>
#include <math.h>

using namespace std;

typedef string tokenValue;
typedef double numv;
typedef string  cellv;
typedef string  oprv;
typedef string  nodev;

typedef string name;

const string functions =" +0 -0 *1 /1 sin2 cos2 tag2 cot2 sum2 ";

enum tokenType{ NUMBER, VARIABLE, LPARENTHESIS, RPARENTHESIS, OPERATOR, FUNCTION, NONE};

struct token{
    string value;
    tokenType type;
};




#endif // DEFINEDTYPES_H
