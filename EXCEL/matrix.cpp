#include "matrix.h"

 void matrix::resize(int w,int h){

  this->setWidth(w);
  this->setHeight(h);
 }

 void matrix::insertCell(int r,int c,string expression){
     cell newCell(r,c);
     newCell.setCurrentSS(this);
     newCell.setExpression(expression);
     spreadSheet[r][c]=newCell;
 }

 cell* matrix::getCell(int r,int c){
     return &spreadSheet[r][c];
 }
