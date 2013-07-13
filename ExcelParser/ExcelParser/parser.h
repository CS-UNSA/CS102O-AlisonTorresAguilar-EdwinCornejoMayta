#ifndef __ExcelParser__parser__
#define __ExcelParser__parser__

#include <iostream>
#include <fstream>
#include <stack>
#include <list>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <math.h>

using namespace std;

const string funciones[]  =   { "ln",
    "log", "abs", "sen", "sin", "cos", "tan", "sec", "csc", "cot", "sgn","rnd",
    "asen", "asin", "acos", "atan", "asec", "acsc", "acot", "senh", "sinh", "cosh", "tanh", "sech", "csch", "coth", "sqrt",
    "round", "asenh", "acosh", "atanh", "asech", "acsch", "acoth"};

class parser
{
	public:
		parser();
		int preOp(char op);
		int esFuncion(string funcion);	
		void parsear(string);
		void imprimir();
        vector <string> getSalida();
	
    private:
		string buffer;
		string bufferAux;
		stack<string> aux;
		vector <string> salida;
	
	
};

#endif /* defined(__ExcelParser__evaluator__) */
