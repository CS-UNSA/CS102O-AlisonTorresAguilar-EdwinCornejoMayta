#ifndef NODENUMBER_H
#define NODENUMBER_H
#include "node.h"

class nodeNumber: public node
{
protected:
    string vnumb;//cambiar
public:
    nodeNumber();

    void print(){
    cout<<vnumb<<":)"<<endl;
    }
    void  setValue(string n){
    vnumb=n;
    }

};

#endif // NODENUMBER_H
