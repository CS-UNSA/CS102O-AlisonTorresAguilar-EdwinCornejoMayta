#ifndef SYNTAXTREE_H
#define SYNTAXTREE_H

#include <cassert>
#include "node.h"
#include "nodecell.h"
#include "nodenumber.h"
#include "nodeoperation.h"
#include "evaluator.h"
#include "definedtypes.h"
#include "parser.h"

using namespace std;
class matrix;
class cell;
class syntaxTree
{
protected:
    node *root;
    evaluator * eval;
public:

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
    void setCurrentSS(matrix *m);
    void setCurrentC(cell *c);

private:
      void inorder(node *p) const;
      void preorder(node *p) const;
      void postorder(node *p) const;
      numv evaluate(node *p)const;

      list<token>  outputList;
      matrix   *currentMatrix;
      cell     *currentCell;
};

#endif // SYNTAXTREE_H
