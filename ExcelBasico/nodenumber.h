#ifndef NODENUMBER_H
#define NODENUMBER_H
#include "node.h"

class nodeNumber: public node
{

private:
    numv value;
    numv  toNumv( string s );

public:
    nodeNumber();
    void print();
    void* getValue();
    void setValue(nodev v);

};

#endif // NODENUMBER_H
