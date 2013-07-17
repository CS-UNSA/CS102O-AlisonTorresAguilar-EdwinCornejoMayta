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

void cell::addUsedBy(cell* p){
    usedBy.push_back(p);
}
