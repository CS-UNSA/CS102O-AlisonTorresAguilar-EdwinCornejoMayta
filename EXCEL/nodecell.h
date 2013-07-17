#ifndef NODECELL_H
#define NODECELL_H

#include "node.h"
#include  "cell.h"

class cell;
class nodeCell: public node
{
private:
    cellv value;
    cell *pcell;

public:
    nodeCell();
    void print();
    void* getValue();
    void setValue(cellv v);
    void setCell(cell *p);
};

#endif // NODECELL_H
