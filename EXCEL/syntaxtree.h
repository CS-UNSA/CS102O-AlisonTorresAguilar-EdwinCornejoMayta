#ifndef SYNTAXTREE_H
#define SYNTAXTREE_H

#include <cassert>
#include "node.h"
#include "nodecell.h"
#include "nodenumber.h"
#include "nodeoperation.h"
#include "evaluator.h"
#include "definedtypes.h"

using namespace std;
class syntaxTree
{
protected:
 node *root;
evaluator * eval;
public:
    /**
     * @brief syntaxTree Empty cosntructor of the class
     */
    syntaxTree():root(NULL){}

    /**
     * @brief syntaxTree cosntructor of the class
     * @param l list of tokens for the syntas tree
     */
    syntaxTree(const list<token> l):root(NULL){outputList=l;}
    //inline bool isEmpty() const{return (root == NULL);}

    /**
     * @brief isEmpty
     * @return return true if the binary tree is empty, otherwise returns false
     */
    inline bool isEmpty() const{return (root == NULL);}

    /** @brief destroyTree:Deallocates the memory space occupied by the tree.
    *   Postcondition: root = NULL;
    */
    void destroyTree();

    /** @brief search:Function to determine if searchItem is in the tree.
    *   Postcondition: Returns true if searchItem is found in the
    *   binary search tree; otherwise, returns false.
    *   @param searchItem the item to search
    */
    bool search(const int &searchItem) const;

    /** @brief insert:Function to insert insertItem in the binary search tree.
    *   Postcondition: If no node in the binary search tree has the
    *   same info as insertItem, a node with the info insertItem
    *   is created and inserted in the binary search tree.
    *   @param insertItem the item to insert
    */
     void insert(const node& itemToInsert);


     /**
      * @brief deleteNode: Function to delete deleteItem from the binary search tree
      *  Postcondition: If a node with the same info as deleteItem
      *  is found, it is deleted from the binary search tree.
      * @param deleteItem the item to delete
      */
     void deleteNode(const int& deleteItem);

      /**
       * @brief inorderTraversal:Function to do an inorder traversal of the binary tree.
       */
      void inorderTraversal() const;

      /**
       * @brief preorderTraversal:Function to do a preorder traversal of the binary tree.
       */
      void preorderTraversal() const;

      /**
       * @brief postorderTraversal:Function to do a preorder traversal of the binary tree.
       */
      void postorderTraversal() const;

      /**
       * @brief buildBinaryTree, This function build the new binary tree
       */
      void buildBinaryTree();

      /**
       * @brief evaluateTree
       */
      numv evaluateTree();


      void  built(string expression);
private:

      /**
       * @brief inorder:Function to do an inorder traversal of the binary tree to which p points.
       * @param p
       */
      void inorder(node *p) const;

      /**
       * @brief preorder:Function to do a preorder traversal of the binary tree to which p points.
       * @param p
       */
      void preorder(node *p) const;

      /**
       * @brief postorder:Function to do a postorder traversal of the binary tree to which p points.
       * @param p
       */
      void postorder(node *p) const;

      /**
       * @brief evaluate
       * @param p
       * @return
       */
      numv evaluate(node *p)const;
      list<token>  outputList;

};

#endif // SYNTAXTREE_H
