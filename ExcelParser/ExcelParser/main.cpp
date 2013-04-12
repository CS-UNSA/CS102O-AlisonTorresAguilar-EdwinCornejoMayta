//
//  main.cpp
//  ExcelParser
//
//  Created by Alison Torres Aguilar - Edwin Cornejo Mayta on 11/04/13.
//  Copyright (c) 2013 CS-UNSA. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;


int main(int argc, const char * argv[])
{
    
    stack<string> S;
    S.push("86");
    S.push("34");
    S.push("22");
    cout<<S.top();
    
    return 0;
}

