#include "matrix.h"

 void matrix::resize(int w,int h){

  this->setWidth(w);
  this->setHeight(h);
 }

 void matrix::insertCell(int r,int c,string expression){
     spreadSheet[r][c].setCurrentSS(this);
     spreadSheet[r][c].setExpression(expression);

 }

 void matrix::updateCell(int r,int c,string expression){
     spreadSheet[r][c].setExpression(expression);
 }

 cell* matrix::getCell(int r,int c){
     return &spreadSheet[r][c];
 }

 bool matrix::loadFromFile(){
     ifstream file(filename);
     int row,col;
     char expr[50];
     while(!file.eof())
     {
             file>>row;
             file>>col;
             file.getline(expr,50,'#');
             spreadSheet[row][col].setExpression(expr);
     }

     file.close();
     return 0;
 }

 bool matrix::writeTofile(){

 }
