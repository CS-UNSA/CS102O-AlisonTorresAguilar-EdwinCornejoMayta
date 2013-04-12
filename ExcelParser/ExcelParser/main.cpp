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
    string entrada="-4*(-5-2)/(-1*2=x-(-3))";
   
    for (int a=0; a<entrada.size(); ++a) {
        if (entrada[a]>='0' && entrada[a]<='9'){
        
        }
        
    }
    

        
        
    
    return 0;
}

