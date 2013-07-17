#include "nodecell.h"

nodeCell::nodeCell(){
}

void nodeCell::print(){
    cout<<value<<endl;
}

void* nodeCell::getValue(){
    return &value;
}

void nodeCell::setValue(cellv v){
     value=v;
 }

void nodeCell::setCell(cell *p){
    pcell = p;
}
