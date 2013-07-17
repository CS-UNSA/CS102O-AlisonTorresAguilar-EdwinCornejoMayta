#include "cell.h"
#include "syntaxtree.h"
#include "matrix.h"
cell::cell(){
}

 void cell::setExpression(string e){
     tree=new syntaxTree();
     tree->setCurrentC(this);
     tree->setCurrentSS(currentMatrix);
     expression=e;
     tree->built(expression);
     value=tree->evaluateTree();
 }


 void cell::print (){
     cout<<"Esto es:"<<endl;
 }

void cell::addUsedBy(cell* p){
    usedBy.push_back(p);
}

void cell::setCurrentSS(matrix *m){
    currentMatrix=m;
}
