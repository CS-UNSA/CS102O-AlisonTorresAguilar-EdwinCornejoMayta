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
    /**
     * @brief nodeOperation
     */
    nodeOperation();

    /**
     * @brief print
     */
    void print();

    /**
     * @brief getValue
     * @return
     */
    void*getValue();

    /**
     * @brief setValue
     * @param v
     */
    void setValue(oprv v);
};

#endif // NODEOPERATION_H
