#ifndef CELL_H
#define CELL_H
#include <string>
#include <vector>
#include "definedtypes.h"
//#include "spreadsheet.h"

using namespace std;

class syntaxTree;
class spreadSheet;
class cell
{
private:

    int         row;
    int         col;
    string      expression;//formula
    syntaxTree   *tree;
    vector<cell*> usedBy;
    numv             value;
    spreadSheet  *ssp;

public:
    cell(){}
    cell(spreadSheet*p ):ssp(p){}

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
    /**
     * @brief setExpression
     * @param e
     */
    void setExpression(string e);

    string getExpression();

    numv getResult(){
        //value = evaluarsintayxtree
        return value;
    }

    void addUsedBy(cell * p);

    //cell* returnThis()
};
#endif // CELL_H
