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
#include <vector>
#include <string.h>
#include <map>
#include <sstream>

using namespace std;

int toInt( string s ){
    int n;
    stringstream ss( s );
    ss>>n;
    return n;
}

double  toDouble( string s ){
    double n;
    stringstream ss( s );
    ss>>n;
    return n;
}

string toStr( int n ){
    string s;
    stringstream ss;
    ss<<n;
    ss>>s;
    return s;
}

bool isNumber(string word){
	bool flag =true ;
	int i= (word[0]=='-'||word[0]=='+');
	for(;i<(int)word.length();++i)
		flag=flag && (isdigit(word[i])||word[i]=='.');
		
	return flag;
	}

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
    for(int i =1;i<=(int)(sizeof(funciones)/sizeof(string));++i){
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
    vector <string> salida;
    
    						
  
   //buffer  = "X1+tan(x)-(233+(11+1)/25*(61+X/2)";
   //buffer  = "ln((+2)*(ln(log((-3)/(-1)))-10)*(-1))";
   buffer  = "(-7+-1)/7.0"; 
	//buffer ="1+242/12*12";
	//buffer = "ln(1+(-100)/log(x+tan(5/3))*(-6)";
	//buffer="(-1)*3/(-1)";
    //buffer = "ln((-2)/(-1)+2)";
    bufferAux="";
	for(int i =0;i<(int)buffer.size();++i){
			if(isdigit(buffer[i])){
				bufferAux=buffer[i];
				while(i+1<(int)buffer.size()&&(isdigit(buffer[i+1]) || buffer[i+1]=='.')){
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
                if(buffer[i+1]=='+'||buffer[i+1]=='-'){
                    ++i;
                    bufferAux=buffer[i];
                    while(i+1<(int)buffer.size()&&isdigit(buffer[i+1])){
                        ++i;
                        bufferAux+=buffer[i];
                    }
                    
                    salida.push_back(bufferAux);
                    bufferAux="";				
                }
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
	
	stack<double> eval;
	string temp;
	double op1,op2,rpt;
	while(!salida.empty()){
		temp =salida.front();
		if(isNumber(temp)){
			eval.push(toDouble(temp));
			cout<<temp<<endl;}
		else{
				op1=eval.top();
				eval.pop();
				op2=eval.top();
				eval.pop();
				switch(temp[0])
				{
					case '+':
									rpt=op2+op1;
									
						break;
					case '-':
									rpt=op2-op1;
						break;
					case '/':
									rpt=op2/op1;
						break;
					case '*':
									rpt=op2*op1;
						break;
				}
				eval.push(rpt);
				}
		
		salida.erase(salida.begin());
	}
	
	cout<<eval.top()<<endl;
	
	
	/// FIN del postFijo
	/*
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
    */
    return 0;
}
