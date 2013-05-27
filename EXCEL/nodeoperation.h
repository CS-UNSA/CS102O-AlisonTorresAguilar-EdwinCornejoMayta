#ifndef NODEOPERATION_H
#define NODEOPERATION_H
#include "node.h"

class nodeOperation : public node
{
private:
    node * pleft,*pright;
public:
    nodeOperation();

};

#endif // NODEOPERATION_H
