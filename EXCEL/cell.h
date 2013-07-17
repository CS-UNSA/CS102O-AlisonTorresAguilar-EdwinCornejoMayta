#ifndef CELL_H
#define CELL_H
#include <string>
#include <vector>
#include "definedtypes.h"
<<<<<<< HEAD
#include "node.h"

=======
//#include "spreadsheet.h"
>>>>>>> 3c4e6badd4550db674e5bdf7ab536d749d3c2cb7

using namespace std;

class syntaxTree;
<<<<<<< HEAD
=======
class spreadSheet;
>>>>>>> 3c4e6badd4550db674e5bdf7ab536d749d3c2cb7
class cell
{

private:
    int         row;
    int         col;
<<<<<<< HEAD
    string      expression;
    syntaxTree  *tree;
    vector<cell*> usedBy;
    numv         value;

public:
    cell();
    cell(int r,int c):row(r),col(c){}
    inline void setRow(int r) {row=r;}
    inline void setCol(int c) {col=c;}
    inline int getRow()const{return row;}
    inline int getCol()const{return col;}
    inline void setValue(numv val){value=val;}
    inline numv getValue(){return value;}
    inline string getExpression(){return expression;}
    void setExpression(string e);
    void print ();
    void addUsedBy(cell* p);
=======
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
>>>>>>> 3c4e6badd4550db674e5bdf7ab536d749d3c2cb7

    //cell* returnThis()
};
#endif // CELL_H
