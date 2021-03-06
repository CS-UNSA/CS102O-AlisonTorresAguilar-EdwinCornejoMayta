#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>
#include "cell.h"
#include <fstream>
//#include "definedtypes.h"
using namespace std;
class matrix
{

private:
    vector< vector<cell > > spreadSheet;
    int currentRow,currentCol;
    int height,width;
    char *filename;

public:
    matrix():height(0),width(0){}
    matrix(int h=100,int w=100):height(h),width(w){ spreadSheet.resize( w,vector<cell>(h));}
    inline void setCurrentRow(int row){currentRow=row;}
    inline int getCurrentRow(){return currentRow;}
    inline void setCurrentCol(int col){currentCol=col;}
    inline int getCurrentCol(){return currentCol;}
    inline void setHeight(int h){height=h;}
    inline int getHeight(){return height;}
    inline void setWidth(int w){width=w;}
    inline int getWidth(){return width;}
    void addRow();
    void addCol();
    void resize(int w,int h);
    void insertCell(int r,int c,string expression);
    void updateCell(int r,int c,string expression);
    cell* getCell(int r,int c);
    inline void setFile(char * f){filename=f;}
    bool loadFromFile();
    bool writeTofile();
};

#endif // MATRIX_H
