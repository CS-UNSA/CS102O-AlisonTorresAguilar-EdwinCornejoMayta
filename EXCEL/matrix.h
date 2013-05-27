#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>
#include "cell.h"

using namespace std;
class matrix
{
private:
    vector< vector<cell > > spredSheet;
    int currentRow,currentCol;
    int height,width;
public:
    matrix():height(0),width(0){}

    matrix(int h,int w):height(h),width(w){}

    inline void setCurrentRow(int row){currentRow=row;}

    inline int getCurrentRow(){return currentRow;}

    inline void setCurrentCol(int col){currentCol=col;}

    inline int getCurrentCol(){return currentCol;}

    inline void setHeight(int h){height=h;}

    inline int getHeight(){return height;}

    inline void setWidth(int w){width=w;}

    inline int getWidth(){return width;}

    inline void addRow();

    inline void addCol();

    inline void increaseSize(int h,int h);


};

#endif // MATRIX_H
