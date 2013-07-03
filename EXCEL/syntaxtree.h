#ifndef SYNTAXTREE_H
#define SYNTAXTREE_H

#include <cassert>
#include "node.h"
#include "nodecell.h"
#include "nodenumber.h"
#include "nodeoperation.h"

using namespace std;
class syntaxTree
{
protected:
 node *root;

public:
    syntaxTree():root(NULL){}

    /** Returns true if the binary tree is empty otherwise, returns false.*/
    inline bool isEmpty() const{return (root == NULL);}

    /** Deallocates the memory space occupied by the tree.
    *   Postcondition: root = NULL; */
    void destroyTree();

    /** Function to determine if searchItem is in the tree.
    *   Postcondition: Returns true if searchItem is found in the
    *   binary search tree; otherwise, returns false.
    *   @param searchItem the item to search  */
    bool search(const int &searchItem) const;

    /** Function to insert insertItem in the binary search tree.
    *   Postcondition: If no node in the binary search tree has the
    *   same info as insertItem, a node with the info insertItem
    *   is created and inserted in the binary search tree.
    *   @param insertItem the item to insert */
     void insertRight(const node& itemToInsert);
     void insertLeft(const  node& itemToInsert);

     /** Function to delete deleteItem from the binary search tree
     *   Postcondition: If a node with the same info as deleteItem
     *   is found, it is deleted from the binary search tree.
     *   @param deleteItem the item to delete */
      void deleteNode(const int& deleteItem);

};

#endif // SYNTAXTREE_H
