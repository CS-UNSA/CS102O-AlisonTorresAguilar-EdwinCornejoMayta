#ifndef CELL_H
#define CELL_H
#include <string>
#include <vector>
#include "definedtypes.h"
//#include "syntaxtree.h"

using namespace std;

class cell
{
private:

    int         row;
    int         col;
    string      expression;
   // syntaxTree   *tree;
    vector<cell> usedBy;
public:
    cell();
    /**
     * @brief setRow
     * @param row
     */
    void setRow(int row);

    /**
     * @brief setCol
     * @param col
     */
    void setCol(int col);

    /**
     * @brief getRow
     * @return
     */
    int getRow();
    /**
     * @brief getCol
     * @return
     */
    int getCol();

    void setExpression(string e);

    string getExpression();



};
#endif // CELL_H
