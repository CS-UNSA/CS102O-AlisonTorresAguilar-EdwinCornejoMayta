#ifndef NODENUMBER_H
#define NODENUMBER_H
#include "node.h"

class nodeNumber: public node
{

private:
    numv value;
    numv  toNumv( string s );

public:
    /**
     * @brief nodeNumber
     */
    nodeNumber();

    /**
     * @brief print
     */
    void print();

    /**
     * @brief getValue
     * @return
     */
    void* getValue();

    /**
     * @brief setValue
     * @param v
     */
    void setValue(nodev v);

};

#endif // NODENUMBER_H
