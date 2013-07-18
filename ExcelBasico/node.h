#ifndef NODE_H
#define NODE_H

#include "definedtypes.h"
#include "iostream"
class node
{
protected:
    node *leftchild,*rightchild;
    int value;// info o valor
public:

    node():leftchild(NULL),rightchild(NULL){}
    node(node*l,node*r):leftchild(l),rightchild(r){}

    virtual void print()=0;
    virtual void*getValue()=0;
    virtual void setValue(nodev)=0;

    inline void setLeft (node &l){leftchild=&l;}
    inline void setRight(node &r){rightchild=&r;}
    node* getLeft (){return leftchild;}
    node* getRight(){return rightchild;}
    bool isLeaft();
    bool isBinary();
    bool isUnary();


};

#endif // NODE_H
