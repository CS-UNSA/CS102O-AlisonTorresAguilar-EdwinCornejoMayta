#include "matrix.h"

 void matrix::resize(int w,int h){
<<<<<<< HEAD

=======
  spreadSheet.resize( w,vector<cell>(h));
>>>>>>> 3c4e6badd4550db674e5bdf7ab536d749d3c2cb7
  this->setWidth(w);
  this->setHeight(h);
 }

 void matrix::insertCell(int r,int c,string expression){
     cell newCell(r,c);
     newCell.setExpression(expression);
     spreadSheet[r][c]=newCell;
 }

 cell* matrix::getCell(int r,int c){
     return &spreadSheet[r][c];
 }
