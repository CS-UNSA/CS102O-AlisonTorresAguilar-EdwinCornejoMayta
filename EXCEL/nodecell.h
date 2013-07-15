#ifndef NODECELL_H
#define NODECELL_H

#include "node.h"
//#include "cell.h"
//:)

class cell;
class nodeCell: public node
{
public:
    //private:
    cellv value;
    numv nvalue;
//protected:
    cell *pcell;


    nodeCell();

    inline void print(){
   cout<<value<<endl;
    }

    inline void* getValue(){

       // return &pcell->gelResult();
        return &value;
    }

    void setPcell(cell * p){
        pcell=p;
    }
    inline void setValue(cellv v){
         value=v;
     }

    inline void setnValue(numv v){
         nvalue=v;
     }
    int getRow(){
        return value[0]-'A';

    }
    int getCol(){
        return value[1]-'0';
    }

};

#endif // NODECELL_H
