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
    /**
     * @brief matrix
     */
    matrix():height(0),width(0){}

    /**
     * @brief matrix
     * @param h
     * @param w
     */
    matrix(int h=100,int w=100):height(h),width(w){ spreadSheet.resize( w,vector<cell>(h));}

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
     * @brief setHeight
     * @param h
     */
    inline void setHeight(int h){height=h;}

    /**
     * @brief getHeight
     * @return
     */
    inline int getHeight(){return height;}

    /**
     * @brief setWidth
     * @param w
     */
    inline void setWidth(int w){width=w;}

    /**
     * @brief getWidth
     * @return
     */
    inline int getWidth(){return width;}

    /**
     * @brief addRow
     */
    void addRow();

    /**
     * @brief addCol
     */
    void addCol();

    /**
     * @brief resize
     * @param w
     * @param h
     */
    void resize(int w,int h);

    /**
     * @brief insertCell
     * @param r
     * @param c
     * @param expression
     */
    void insertCell(int r,int c,string expression);

    /**
     * @brief updateCell
     * @param r
     * @param c
     * @param expression
     */
    void updateCell(int r,int c,string expression);

    /**
     * @brief getCell
     * @param r
     * @param c
     * @return
     */
    cell* getCell(int r,int c);

    /**
     * @brief setFile
     * @param f
     */
    inline void setFile(char * f){filename=f;}

    /**
     * @brief loadFromFile
     * @return
     */
    bool loadFromFile();

    /**
     * @brief writeTofile
     * @return
     */
    bool writeTofile();

    /**
     * @brief getTextAt
     * @param row
     * @param col
     * @return
     */
    string getTextAt(int row,int col);

    /**
     * @brief getFormulaAt
     * @param row
     * @param col
     * @return
     */
    string getFormulaAt(int row,int col);

    /**
     * @brief getValueAt
     * @param row
     * @param col
     * @return
     */
    double getValueAt(int row,int col);

    /**
     * @brief toStr
     * @param n
     * @return
     */
    string toStr( numv n );
    void updateCell(int r,int c);
};

#endif // MATRIX_H
