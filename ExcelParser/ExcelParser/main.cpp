//
//  main.cpp
//  ExcelParser
//
//  Created by Alison Torres Aguilar - Edwin Cornejo Mayta on 11/04/13.
//  Copyright (c) 2013 CS-UNSA. All rights reserved.
//
//:)
#include <iostream>
#include <fstream>
#include <stack>
#include <list>
#include <vector>
#include <string.h>
#include <map>
#include <sstream>
#include "evaluator.h"
//#include "eval.h"
#include <string>
#include "parser.h"
using namespace std;

int main(){
    parser a;
    a.parsear("sin((6+5-X)/5)");
    a.imprimir();
   
    

   char x;
cin>>x;
    return 0;
};
