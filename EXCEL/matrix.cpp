#include "matrix.h"

 void matrix::resize(int w,int h){
  spreadSheet.resize( w,vector<cell>(h));
  this->setWidth(w);
  this->setHeight(h);
 }
