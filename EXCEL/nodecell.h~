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

    inline void print(){
   cout<<value<<endl;
    }

    inline void* getValue(){
        return &value;
    }

    inline void setValue(cellv v){
         value=v;
     }


};

#endif // NODECELL_H
