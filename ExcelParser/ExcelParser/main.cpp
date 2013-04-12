//
//  main.cpp
//  ExcelParser
//
//  Created by Alison Torres Aguilar - Edwin Cornejo Mayta on 11/04/13.
//  Copyright (c) 2013 CS-UNSA. All rights reserved.
//

#include <iostream>
#include <stack>
#include <list>
using namespace std;


int main(int argc, const char * argv[])
{
    
    stack<string> postfija;
    list<string> salida;
    string entrada="-467*(-5-2)/(-1*2=x-(-3))";
    string bufferNum="";
    for (int a=0; a<entrada.size(); ++a) {
        if (entrada[a]>='0' && entrada[a]<='9'){
            
            //for (int b=0;(a+b)<=entrada.size()&&(entrada[a+b]>='0' && entrada[a+b]<='9');++b){
              //  buffer+=entrada[a+b];
            //}
            bufferNum+=entrada[a];
                cout<<bufferNum<<" Es un numero"<<endl;
            
        }
        
        else if ((entrada[a]>='a' && entrada[a]<='z')|| (entrada[a]>='A' && entrada[a]<='Z')){
            cout<<entrada[a]<<" Es un variable"<<endl;
            bufferNum="";
        }
        
        else if (entrada[a]=='('){
            cout<<entrada[a]<<" parentesis izquierdo"<<endl;
            bufferNum="";
        }
        else if (entrada[a]==')'){
            cout<<entrada[a]<<" parentesis derecho"<<endl;
            bufferNum="";
        }
        
        else {
                cout<<entrada[a]<<" operador"<<endl;
            bufferNum="";
        }
        
    }
    

        
        
    
    return 0;
}

