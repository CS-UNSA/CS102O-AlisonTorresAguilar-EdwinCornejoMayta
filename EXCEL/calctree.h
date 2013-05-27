#ifndef CALCTREE_H
#define CALCTREE_H

class calcTree
{
public:
    calcTree(); //constructor por defecto
    calcTree(calcTree &);
    ~calcTree();

    void setRoot();
    void setLeftChild();
    void setRigthChild();
    void printIN();
};

#endif // CALCTREE_H
