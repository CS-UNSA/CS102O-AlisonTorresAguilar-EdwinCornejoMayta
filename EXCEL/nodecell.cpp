#include "nodecell.h"
#include "matrix.h"
#include "string.h"

nodeCell::nodeCell(){
}

void nodeCell::print(){
    cout<<value<<endl;
}

void* nodeCell::getValue(){
    numv val=(pcell->getValue());
    return &val;
}

void nodeCell::setValue(cellv v){
     value=v;
 }

void nodeCell::setMatrix(matrix *m){
    getRowCol();
    pcell=m->getCell(row,col);
    if(pcell->isEmpty())
         throw "There is a reference to a empty cell!";

}

void nodeCell::addUsedBy(cell *toAdd){
    if(toAdd!=pcell)
    pcell->addUsedBy(toAdd);
    else
        throw "There is an circular reference!!";
}
void nodeCell::getRowCol(){

    col=value[0]-(islower(value[0])?'a':'A');
    cout<<" ssssssss" <<col<<endl;
    row=value[1]-'0'-1;


}
