#ifndef NODEOPERATION_H
#define NODEOPERATION_H
#include "node.h"
class nodeOperation :public node
{
 private:
    oprv value;
protected:
    string nOperation;

public:
    nodeOperation();

    void print(){
    cout<<value<<endl;
    }

    void*getValue(){
    return &value;
    }
     void setValue(oprv v){
         value=v;
     }
};

#endif // NODEOPERATION_H
