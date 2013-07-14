#include "node.h"

bool node::isLeaft(){
   return (getLeft()==NULL && getRight()==NULL);
}

bool node::isBinary(){
    return (getLeft()!=NULL && getRight()!=NULL);
}

bool node::isUnary(){
    return (getLeft()!=NULL && getRight()==NULL);
}
