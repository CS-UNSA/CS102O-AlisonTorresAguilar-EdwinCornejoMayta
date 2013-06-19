#ifndef NODE_H
#define NODE_H

#include "definedtypes.h"

class node
{
private:
    node *leftchild,*rightchild;
    int value;// info o valor
public:
    node():leftchild(NULL),rightchild(NULL){}
    node(node*l,node*r):leftchild(l),rightchild(r){}

   // virtual value getValue();
   // virtual value setValue();
};

#endif // NODE_H
