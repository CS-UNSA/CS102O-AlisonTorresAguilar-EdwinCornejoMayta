#ifndef NODECELL_H
#define NODECELL_H

#include "node.h"
<<<<<<< HEAD
#include  "cell.h"
=======
//#include "cell.h"
//:)
>>>>>>> 3c4e6badd4550db674e5bdf7ab536d749d3c2cb7

class cell;
class nodeCell: public node
{
public:
    //private:
    cellv value;
<<<<<<< HEAD
=======
    numv nvalue;
//protected:
>>>>>>> 3c4e6badd4550db674e5bdf7ab536d749d3c2cb7
    cell *pcell;


    nodeCell();
<<<<<<< HEAD
    void print();
    void* getValue();
    void setValue(cellv v);
    void setCell(cell *p);
=======

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

>>>>>>> 3c4e6badd4550db674e5bdf7ab536d749d3c2cb7
};

#endif // NODECELL_H
