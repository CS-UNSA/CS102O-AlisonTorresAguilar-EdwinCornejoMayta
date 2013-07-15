#ifndef NODENUMBER_H
#define NODENUMBER_H
#include "node.h"

class nodeNumber: public node
{

private:
    numv value;
protected:
    string vnumb;//cambiar
public:
    nodeNumber();

    void print(){
    cout<<value<<endl;
    }

    void* getValue(){
        return &value;
    }

     void setValue(nodev v){
         value=toNumv(v);
     }

     numv  toNumv( string s ){
         numv  n;
         stringstream ss( s );
         ss>>n;
         return n;
     }
};

#endif // NODENUMBER_H
