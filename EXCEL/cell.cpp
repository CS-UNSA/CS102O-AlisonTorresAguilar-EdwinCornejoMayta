#include "cell.h"
#include "syntaxtree.h"
#include "matrix.h"
cell::cell(){
   // value=-1;
}

 void cell::setExpression(string e){
     tree=new syntaxTree();
     tree->setCurrentC(this);
     tree->setCurrentSS(currentMatrix);
     expression=e;
     content=tree->built(expression);
     if(content!=TEXT){
     value=tree->evaluateTree();
   //  update();
     }

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
     cout<<"-------------ACTUALIZA------------------"<<endl;
    vector<cell*>::iterator it;
    for(it=usedBy.begin();it!=usedBy.end();it++){
       (*it)->evaluate();
       (*it)->update();
        cout<<"actualiza**************************"<<this->expression<<endl;
    }

}
