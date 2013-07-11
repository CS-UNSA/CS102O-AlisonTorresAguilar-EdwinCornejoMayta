#ifndef CELL_H
#define CELL_H

#include "definedtypes.h"
#include "node.h"
#include <string>
#include <vector>
using namespace std;

class cell
{
private:

    int         row;
    int         col;
    string      expression;
    node        *value;
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

};
#endif // CELL_H
