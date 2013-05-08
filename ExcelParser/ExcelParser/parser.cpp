

#include "parser.h"


parser::parser()
{
	bufferAux="";	
}
int parser::preOp(char op){
    if (op =='+'||op == '-') return 0;
    else if (op == '*'||op == '/') return 1;
    else if (op ==  '^') return 2;
    else
        return -1;																								
    return 0;
};



int parser::esFuncion(string funcion){
    for(int i =1;i<=(int)(sizeof(funciones)/sizeof(string));++i){
        if (funcion==funciones[i-1])
            return i;
    }
    return 0;
}

void parser::parsear(string buffer){
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
	
	
}

void parser::imprimir(){
	cout<<"----------------------------"<<endl;
	while(!salida.empty()){
		cout<<salida.front()<<endl;
        salida.erase(salida.begin());
		//salida.pop_front();
	}
    cout<<"----------------------------"<<endl;
	
	}
