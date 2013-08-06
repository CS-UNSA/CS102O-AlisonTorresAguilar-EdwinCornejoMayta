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
    /**
     * @brief node
     */
    node():leftchild(NULL),rightchild(NULL){}

    /**
     * @brief node
     * @param l
     * @param r
     */
    node(node*l,node*r):leftchild(l),rightchild(r){}

    /**
     * @brief print
     */
    virtual void print()=0;

    /**
     * @brief getValue
     * @return
     */
    virtual void*getValue()=0;

    /**
     * @brief setValue
     */
    virtual void setValue(nodev)=0;

    /**
     * @brief setLeft
     * @param l
     */
    inline void setLeft (node &l){leftchild=&l;}

    /**
     * @brief setRight
     * @param r
     */
    inline void setRight(node &r){rightchild=&r;}

    /**
     * @brief getLeft
     * @return
     */
    node* getLeft (){return leftchild;}

    /**
     * @brief getRight
     * @return
     */
    node* getRight(){return rightchild;}

    /**
     * @brief isLeaft
     * @return
     */
    bool isLeaft();

    /**
     * @brief isBinary
     * @return
     */
    bool isBinary();
    /**
     * @brief isUnary
     * @return
     */
    bool isUnary();


};

#endif // NODE_H
