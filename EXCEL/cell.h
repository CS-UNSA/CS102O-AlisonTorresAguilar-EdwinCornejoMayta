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
    contentType   content;
    bool          empty;
public:
    /**
     * @brief cell
     */
    cell();

    /**
     * @brief cell
     * @param r
     * @param c
     */
    cell(int r,int c):row(r),col(c){}

    /**
     * @brief setRow
     * @param r
     */
    inline void setRow(int r) {row=r;}

    /**
     * @brief setCol
     * @param c
     */
    inline void setCol(int c) {col=c;}

    /**
     * @brief getRow
     * @return
     */
    inline int getRow()const{return row;}

    /**
     * @brief getCol
     * @return
     */
    inline int getCol()const{return col;}

    /**
     * @brief setValue
     * @param val
     */
    inline void setValue(numv val){value=val;}

    /**
     * @brief getValue
     * @return
     */
    numv getValue(){return value;}

    /**
     * @brief getType
     * @return
     */
    inline contentType getType(){return content;}

    /**
     * @brief getExpression
     * @return
     */
    inline string getExpression(){return expression;}

    /**
     * @brief setExpression
     * @param e
     */
    void setExpression(string e);

    /**
     * @brief setCurrentSS
     * @param m
     */
    void setCurrentSS(matrix *m);

    /**
     * @brief print
     */
    void print ();

    /**
     * @brief addUsedBy
     * @param p
     */
    void addUsedBy(cell* p);

    /**
     * @brief update
     */
    void update();

    /**
     * @brief evaluate
     */
    void evaluate();

    inline bool isEmpty() {return empty;}
};
#endif // CELL_H
