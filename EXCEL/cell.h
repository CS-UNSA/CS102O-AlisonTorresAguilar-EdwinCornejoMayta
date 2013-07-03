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
    void setRow(int);
    void setCol(int);
    int getRow();
    int getCol();

};
#endif // CELL_H
