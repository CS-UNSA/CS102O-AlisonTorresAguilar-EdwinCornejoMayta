#ifndef CELL_H
#define CELL_H
#include <string>
#include <vector>
#include "definedtypes.h"
#include "node.h"

using namespace std;

class matrix;
class syntaxTree;
class cell
{

private:
    typeRow       row;
    typeCol       col;
    string        expression;
    syntaxTree    *tree;
    vector<cell*> usedBy;
    numv          value;
    matrix        *currentMatrix;
public:
    cell();
    cell(int r,int c):row(r),col(c){}
    inline void setRow(int r) {row=r;}
    inline void setCol(int c) {col=c;}
    inline int getRow()const{return row;}
    inline int getCol()const{return col;}
    inline void setValue(numv val){value=val;}
     numv getValue(){return value;}
    // string getValue(){return expression;}

    inline string getExpression(){return expression;}
    void setExpression(string e);
    void setCurrentSS(matrix *m);
    void print ();
    void addUsedBy(cell* p);
    void update();
    void evaluate();
};
#endif // CELL_H
