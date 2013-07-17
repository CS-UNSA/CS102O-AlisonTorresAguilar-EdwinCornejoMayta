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
    int row;
    int col;
    void getRowCol();
public:
    nodeCell();
    void print();
    void* getValue();
    void setValue(cellv v);
    void setMatrix(matrix *m);
    void addUsedBy(cell*p);

};

#endif // NODECELL_H
