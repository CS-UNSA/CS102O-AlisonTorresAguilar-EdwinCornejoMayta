//
//  main.cpp
//  Lexer
//
//  Created by Edwin Cornejo Mayta on 24/04/13.
//  Copyright (c) 2013 IS-UNSA. All rights reserved.
//

#include <iostream>
#include <fstream>
//#include <ctype.h>
#include "Lexer.h"


int main(int argc, const char * argv[])
{
    //////////////////////////////////////////////////////////////////////////////
    // cout<<esPReservarda("imprimir")<<endl;
    //////////////////////////////////////////////////////////////////////////////
    Lexer a;
   // cout<<"//"<<endl;
    a.analizar("lectura.txt", "salida.txt");
    
    return 0;
}

