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

using namespace std;

int preOp(char op){
    if (op =='+'||op == '-') return 0;
    else if (op == '*'||op == '/') return 1;
    else if (op ==  '^') return 2;
    else
        return -1;																								
    return 0;
};

string obtCad(string &cad){
	string aux;
	if (cad.size()==0){
			return "";
	}
	else{
		unsigned pos = cad.find(" ");
		aux = cad.substr (0,pos+1);
		cad.replace(0,pos+1,"");
	}
	return aux;
}

int main(int argc, const char * argv[])
{
    string buffer;
    string bufferAux;
    stack<string> aux;
    list <string> salida;
   // cout<<!aux.empty()<<endl;
   buffer  = "(233+(11+1)/25*(61+2))";
	//buffer ="1+242/12*12";
	
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
			
			else if(buffer[i]=='('){
				bufferAux=buffer[i];
				aux.push(bufferAux);
				bufferAux="";
			}
			else if(buffer[i]==')'){
				while(!aux.empty()&&aux.top()[0]!='('){
					salida.push_back(aux.top());
					aux.pop();
				}
				if(!aux.empty()&&aux.top()[0]=='('){
					aux.pop();
				}
				else
					cout<<"Error en el ingreso"<<endl;
			}
			else {
			
				while(!aux.empty()&&preOp(aux.top()[0])>=preOp(buffer[i])){
					salida.push_back(aux.top());
					aux.pop();
				}
				
			//	if(!aux.empty())
			//	cout<<"precedencia "<< aux.top()[0] <<"-"<<preOp(buffer[i])<<endl;
				bufferAux=buffer[i];
				aux.push(bufferAux);
				bufferAux="";
			}	
			
	}	
	
	while(!aux.empty()){
		salida.push_back(aux.top());
		aux.pop();
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
	
    return 0;
}



