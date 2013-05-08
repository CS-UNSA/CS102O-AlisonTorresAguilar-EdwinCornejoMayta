//
//  Lexer.h
//  Lexer
//
//  Created by Edwin Cornejo Mayta on 4/05/13.
//  Copyright (c) 2013 IS-UNSA. All rights reserved.
//

#ifndef __Lexer__Lexer__
#define __Lexer__Lexer__

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <locale>
using namespace std;


const string palReservadas[] = {"imprimir","principal","retornar"};
const string tipoDato[]={"entero","real","caracter","cadena"};
const string operador[]={"(","*",")",";","+","=","{","}","/"};
const string comentario[]={"//","/*","*/"};
const string caracterEscape[]={"\n","\t"};
const string otrosEspeciales[]={"+=","/*","*/"};
//reviar comentarios en el cuerpo
//revisar caracteres de escape
//revisar otros

class Lexer{
public:
    Lexer();
    ~Lexer();
    bool verificarPR(char *);
    bool verificarTD(char *);
    bool verificarOp(char *);
    bool verificarDi(char *);
    bool verificarCo(char *);
    bool verificarCe(char *);
    bool verificarOt(char *);
   // bool esDigito(char* );
    
    void analizar(char*,char*);
    bool analizarAvanzado(char*,ofstream&);
    bool crearToken(char*,ofstream&);
    
    void strcopiar(char * buffer,char * bufferCopia,int ini,int fin);
    void limpiarBuffer(char* buffer);
};

#endif /* defined(__Lexer__Lexer__) */
