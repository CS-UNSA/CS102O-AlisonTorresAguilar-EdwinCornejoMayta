#include "matrix.h"

 void matrix::resize(int w,int h){
  spredSheet.resize( w,vector<cell>(h));
  this->setWidth(w);
  this->setHeight(h);
 }
