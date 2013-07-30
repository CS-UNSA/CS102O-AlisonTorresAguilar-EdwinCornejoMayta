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
     update();
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

void cell::evaluate(){
    value=tree->evaluateTree();
}
void cell::update(){
    vector<cell*>::iterator it;
    for(it=usedBy.begin();it!=usedBy.end();it++){
       (*it)->evaluate();
       (*it)->update();
    }

}
