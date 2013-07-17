#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <vector>
#include <string>
#include "cell.h"

using namespace std;
class spreadSheet
{

private:
<<<<<<< HEAD
    vector< vector<cell > > spreadSheet;
    int currentRow,currentCol;
    int height,width;

public:
=======
    vector< vector<cell > > matrix;
    int currentRow,currentCol;
    int height,width;
public:
    /**
     * @brief matrix
     */
   spreadSheet():height(0),width(0){}

    spreadSheet(int h,int w):height(h),width(w){}
>>>>>>> 3c4e6badd4550db674e5bdf7ab536d749d3c2cb7

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
<<<<<<< HEAD
    void addRow();
    void addCol();
    void resize(int w,int h);
    void insertCell(int r,int c,string expression);
    cell* getCell(int r,int c);
=======

    /**
     * @brief addRow
     */
    inline void addRow();

    /**
     * @brief addCol
     */
    inline void addCol();

    /**
     * @brief resize
     * @param w is de new width to set
     * @param h is de new height to set
     */
    inline void resize(int w,int h);

    cell* getCell(int r,int c){ return &matrix[r][c];}
>>>>>>> 3c4e6badd4550db674e5bdf7ab536d749d3c2cb7
};

#endif // MATRIX_H
