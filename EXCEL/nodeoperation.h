#ifndef NODEOPERATION_H
#define NODEOPERATION_H
#include "node.h"
class nodeOperation :public node
{
protected:
    string nOperation;

public:
    nodeOperation();

    void print(){
    cout<<nOperation<<endl;
    }

    void  setValue(name o){
    nOperation=o;
    }
};

#endif // NODEOPERATION_H
