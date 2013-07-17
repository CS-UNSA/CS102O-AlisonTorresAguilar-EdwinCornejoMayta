#include "spreadsheet.h"

<<<<<<< HEAD
spreadSheet::spreadSheet()
{
}
=======
 void spreadSheet::resize(int w,int h){
  matrix.resize( w,vector<cell>(h));
  this->setWidth(w);
  this->setHeight(h);
 }
>>>>>>> 3c4e6badd4550db674e5bdf7ab536d749d3c2cb7
