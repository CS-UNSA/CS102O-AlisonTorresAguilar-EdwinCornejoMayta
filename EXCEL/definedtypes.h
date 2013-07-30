#ifndef DEFINEDTYPES_H
#define DEFINEDTYPES_H

#include <string>
#include <map>
#include <stack>
#include <list>
#include <sstream>
#include <math.h>

using namespace std;

typedef unsigned int size;
typedef string tokenValue;
typedef double  numv;
typedef string  cellv;
typedef string  oprv;
typedef string  nodev;
typedef string  expression;
typedef int     position;
typedef int     typeCol;
typedef int     typeRow;
const string functions =" +0 -0 *1 /1 %1 sin2 cos2 tan2 ctg2 sec2 csc2 abs2 sqrt2";

enum tokenType{ NUMBER, VARIABLE, LPARENTHESIS, RPARENTHESIS, OPERATOR, FUNCTION,SEPARATOR,NONE};

struct token{
    string value;
    tokenType type;
};

#endif // DEFINEDTYPES_H
