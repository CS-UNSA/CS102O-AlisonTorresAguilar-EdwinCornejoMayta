#ifndef NODECELL_H
#define NODECELL_H

#include "node.h"
#include  "cell.h"

class cell;
class matrix;
class nodeCell: public node
{
private:

    cellv value;
    cell *pcell;
    matrix *currentMatrix;
    typeRow  row;
    typeCol  col;
    void getRowCol();
public:
    /**
     * @brief nodeCell
     */
    nodeCell();

    /**
     * @brief print
     */
    void print();

    /**
     * @brief getValue
     * @return
     */
    void* getValue();

    /**
     * @brief setValue
     * @param v
     */
    void setValue(cellv v);

    /**
     * @brief setMatrix
     * @param m
     */
    void setMatrix(matrix *m);

    /**
     * @brief addUsedBy
     * @param p
     */
    void addUsedBy(cell*p);

};

#endif // NODECELL_H
