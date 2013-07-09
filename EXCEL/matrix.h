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
    /**
     * @brief matrix
     */
    matrix():height(0),width(0){}

    matrix(int h,int w):height(h),width(w){}

    /**
     * @brief setCurrentRow
     * @param row
     */
    inline void setCurrentRow(int row){currentRow=row;}

    /**
     * @brief getCurrentRow
     * @return
     */
    inline int getCurrentRow(){return currentRow;}

    /**
     * @brief setCurrentCol
     * @param col
     */
    inline void setCurrentCol(int col){currentCol=col;}

    /**
     * @brief getCurrentCol
     * @return
     */
    inline int getCurrentCol(){return currentCol;}

    /**
     * @brief setHeight set a new value for matrix's width
     * @param h
     */
    inline void setHeight(int h){height=h;}

    /**
     * @brief getHeight
     * @return  the matrix's height
     */
    inline int getHeight(){return height;}

    /**
     * @brief setWidth set a new value for matrix's width
     * @param w
     */
    inline void setWidth(int w){width=w;}
    /**
     * @brief getWidth
     * @return  the matrix's width
     */
    inline int getWidth(){return width;}

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


};

#endif // MATRIX_H
