//
//  main.cpp
//  ExcelParser
//
//  Created by Alison Torres Aguilar - Edwin Cornejo Mayta on 11/04/13.
//  Copyright (c) 2013 CS-UNSA. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stack>
#include <list>
#include <string.h>
#include <map>

using namespace std;

int preOp(char op){
    if (op =='+'||op == '-') return 0;
    else if (op == '*'||op == '/') return 1;
    else if (op ==  '^') return 2;
    else
        return -1;																								
    return 0;
};

const string funciones[]  =   { "ln",
    "log", "abs", "sen", "sin", "cos", "tan", "sec", "csc", "cot", "sgn","rnd",
    "asen", "asin", "acos", "atan", "asec", "acsc", "acot", "senh", "sinh", "cosh", "tanh", "sech", "csch", "coth", "sqrt",
    "round", "asenh", "acosh", "atanh", "asech", "acsch", "acoth"};


int esFuncion(string funcion){
    for(int i =1;i<=sizeof(funciones)/sizeof(string);++i){
        if (funcion==funciones[i-1])
            return i;
    }
    return 0;
}
	
int main(int argc, const char * argv[])
{
    string buffer;
    string bufferAux;
    stack<string> aux;
    list <string> salida;
    
    						
   // cout<<!aux.empty()<<endl;
   //buffer  = "X1+tan(x)-(233+(11+1)/25*(61+X/2)";
   //buffer  = "3+(-1)";
	//buffer ="1+242/12*12";
	buffer = "ln(1+100/log(x+tan(5/3))*6)";
	bufferAux="";
	for(int i =0;i<(int)buffer.size();++i){
			if(isdigit(buffer[i])){
				bufferAux=buffer[i];
				while(i+1<(int)buffer.size()&&isdigit(buffer[i+1])){
					++i;
					bufferAux+=buffer[i];
				}
				
				salida.push_back(bufferAux);
				bufferAux="";				
			}
			////////////////////////////////////
			else if(isalpha(buffer[i])){
                bufferAux=buffer[i];
				while(i+1<(int)buffer.size()&&isalnum(buffer[i+1])){
					++i;
					bufferAux+=buffer[i];
				}
                /// aqui se coloca si es una funcion que esta en la tabla entonces se trata como operador
				
                if (esFuncion( bufferAux)) {
                    aux.push(bufferAux);
                    bufferAux="";
                }
                else{
                    salida.push_back(bufferAux);
                    bufferAux="";
                }
			}
            ////////////////////////////////////
			else if(buffer[i]=='('){
				bufferAux=buffer[i];
				aux.push(bufferAux);
				bufferAux="";
			}
			else if(buffer[i]==')'){
				while(!aux.empty()&&aux.top()[0]!='('){//podrian ser aux.top()[0]//aux.top()[aux.top().size()-1]
					salida.push_back(aux.top());
					aux.pop();
				}
				if(!aux.empty()&&aux.top()[0]=='('){//podrian ser aux.top()[0]
					aux.pop();
				}
				else
					cout<<"Error en el ingreso"<<endl;
			}
			else {
			
				while(!aux.empty()&&(esFuncion(aux.top())||preOp(aux.top()[0])>=preOp(buffer[i]))){
					salida.push_back(aux.top());
					aux.pop();
				}
				bufferAux=buffer[i];
				aux.push(bufferAux);
				bufferAux="";
			}	
			
	}	
	
	while(!aux.empty()){
        if (aux.top()[aux.top().size()-1]!='(') {
            salida.push_back(aux.top());
            aux.pop();
        }
        else{
            cout<<"Error en el ingreso"<<endl;
            aux.pop();
        }
	}
	
	/// FIN del postFijo
	cout<<"----------------------------"<<endl;
	while(!salida.empty()){
		cout<<salida.front()<<endl;
		salida.pop_front();
	}
    cout<<"----------------------------"<<endl;
	while(!aux.empty()){
		cout<<aux.top()<<endl;
		aux.pop();
	}
	char a;
	cin>>a;
    return 0;
}
