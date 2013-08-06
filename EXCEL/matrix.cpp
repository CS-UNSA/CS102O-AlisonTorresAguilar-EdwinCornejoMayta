#include "matrix.h"
#include  <sstream>
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

 void matrix::updateCell(int r,int c){
     spreadSheet[r][c].update();
 }
 cell* matrix::getCell(int r,int c){
     spreadSheet[r][c].setCurrentSS(this);
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
     ofstream file (filename);
     for (size i=0;i<currentRow;i++){
         for (size j=0;j<currentRow;j++){
             if(!spreadSheet[i][j].isEmpty()){
                file<<spreadSheet[i][j].getRow()<<" ";
                file<<spreadSheet[i][j].getCol()<<" ";
                file<<spreadSheet[i][j].getExpression();
             }
         }
     }
 }

 string matrix::getTextAt(int row,int col){
     return spreadSheet[row][col].getExpression();
 }
 string matrix::getFormulaAt(int row,int col){
     return toStr(spreadSheet [row][col].getValue());
 }

 double matrix::getValueAt(int row,int col){
     return (spreadSheet [row][col].getValue());
 }
 string matrix::toStr( numv n ){
     string s;
     stringstream ss;
     ss<<n;
     ss>>s;
     return s;
 }
