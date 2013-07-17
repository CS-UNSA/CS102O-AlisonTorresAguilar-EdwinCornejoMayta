#include "cell.h"
#include "syntaxtree.h"
cell::cell(){
}

 void cell::setExpression(string e){
     tree=new syntaxTree();
     expression=e;
     tree->built(expression);
     value=tree->evaluateTree();
 }


 void cell::print (){
     cout<<"Esto es:"<<endl;
 }

<<<<<<< HEAD
void cell::addUsedBy(cell* p){
=======
void cell::setExpression(string e){
}

string cell::getExpression(){}


void cell::addUsedBy(cell * p){
>>>>>>> 3c4e6badd4550db674e5bdf7ab536d749d3c2cb7
    usedBy.push_back(p);
}
