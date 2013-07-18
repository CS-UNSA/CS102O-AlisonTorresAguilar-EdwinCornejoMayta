#ifndef NODEOPERATION_H
#define NODEOPERATION_H
#include "node.h"
class nodeOperation :public node
{
 private:
    oprv value;
protected:
    string nOperation;

public:
    nodeOperation();
    void print();
    void*getValue();
    void setValue(oprv v);
};

#endif // NODEOPERATION_H
