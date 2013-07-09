#ifndef NODECELL_H
#define NODECELL_H

#include "node.h"
#include "cell.h"
class nodeCell: public node
{
protected:
    cell *pcell;
    name  nCell;
public:
    nodeCell();

    void print(){
    cout<<nCell<<endl;
    }

    void  setValue(name n){
    nCell=n;
    }
};

#endif // NODECELL_H
