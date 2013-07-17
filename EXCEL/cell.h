#ifndef CELL_H
#define CELL_H
#include <string>
#include <vector>
#include "definedtypes.h"
#include "node.h"


using namespace std;

class syntaxTree;
class cell
{

private:
    int         row;
    int         col;
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

};
#endif // CELL_H
