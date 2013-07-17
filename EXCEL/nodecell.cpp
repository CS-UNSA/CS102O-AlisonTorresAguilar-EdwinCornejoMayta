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
    cout<<val<<"valor"<<endl;
    cout<<"dir="<<pcell<<endl;
    return &val;
}

void nodeCell::setValue(cellv v){
     value=v;
 }

void nodeCell::setMatrix(matrix *m){
    getRowCol();
    pcell=m->getCell(col,row);
}

void nodeCell::addUsedBy(cell *toAdd){
    pcell->addUsedBy(toAdd);
}
void nodeCell::getRowCol(){
    col=value[0]-'A';
    row=value[1]-'0'-1;
    cout<<"col"<<col<<endl;
    cout<<"row"<<row<<endl;
}
