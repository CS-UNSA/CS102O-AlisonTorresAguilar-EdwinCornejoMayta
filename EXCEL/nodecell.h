#ifndef NODECELL_H
#define NODECELL_H

#include "node.h"
#include "cell.h"
class nodeCell: public node
{
private:
    cellv value;
protected:
    cell *pcell;

public:
    nodeCell();

    void print(){
    cout<<value<<endl;
    }

    void* getValue(){
        return &value;
    }
    void setValue(cellv v){
         value=v;
     }

     void mymetod(){
         cout<<"helo"<<endl;
     }
};

#endif // NODECELL_H
