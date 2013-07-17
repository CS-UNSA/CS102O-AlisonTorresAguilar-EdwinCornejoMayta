#ifndef SYNTAXTREE_H
#define SYNTAXTREE_H

#include <cassert>
#include "node.h"
#include "nodecell.h"
#include "nodenumber.h"
#include "nodeoperation.h"
#include "evaluator.h"
#include "definedtypes.h"
<<<<<<< HEAD
#include "parser.h"
=======
#include "spreadsheet.h"
>>>>>>> 3c4e6badd4550db674e5bdf7ab536d749d3c2cb7

using namespace std;
class syntaxTree
{
protected:
     node *root;
    evaluator * eval;
    spreadSheet *ssp;
public:
<<<<<<< HEAD
=======
    /**
     * @brief syntaxTree Empty cosntructor of the class
     */

    syntaxTree(spreadSheet *p):ssp(p){}
    syntaxTree():root(nullptr){}
>>>>>>> 3c4e6badd4550db674e5bdf7ab536d749d3c2cb7

    syntaxTree():root(NULL){}
    syntaxTree(const list<token> l):root(NULL){outputList=l;}
    inline bool isEmpty() const{return (root == NULL);}
    void destroyTree();
    bool search(const int &searchItem) const;
    void insert(const node& itemToInsert);
    void deleteNode(const int& deleteItem);
    void inorderTraversal() const;
    void preorderTraversal() const;
    void postorderTraversal() const;
    void buildBinaryTree();
    numv evaluateTree();
    node*  built(string expression);


<<<<<<< HEAD
=======
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

>>>>>>> 3c4e6badd4550db674e5bdf7ab536d749d3c2cb7
private:
      void inorder(node *p) const;
      void preorder(node *p) const;
      void postorder(node *p) const;
      numv evaluate(node *p)const;

      list<token>  outputList;

};

#endif // SYNTAXTREE_H
