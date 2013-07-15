#include "spreadsheet.h"

 void spreadSheet::resize(int w,int h){
  matrix.resize( w,vector<cell>(h));
  this->setWidth(w);
  this->setHeight(h);
 }
