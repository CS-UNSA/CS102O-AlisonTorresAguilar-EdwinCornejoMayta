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
    /**
     * @brief syntaxTree
     */
    syntaxTree():root(NULL){}

    /**
     * @brief syntaxTree
     * @param l
     */
    syntaxTree(const list<token> l):root(NULL){outputList=l;}

    /**
     * @brief isEmpty
     * @return
     */
    inline bool isEmpty() const{return (root == NULL);}

    /**
     * @brief destroyTree
     */
    void destroyTree();

    /**
     * @brief search
     * @param searchItem
     * @return
     */
    bool search(const int &searchItem) const;

    /**
     * @brief insert
     * @param itemToInsert
     */
    void insert(const node& itemToInsert);

    /**
     * @brief deleteNode
     * @param deleteItem
     */
    void deleteNode(const int& deleteItem);

    /**
     * @brief inorderTraversal
     */
    void inorderTraversal() const;

    /**
     * @brief preorderTraversal
     */
    void preorderTraversal() const;

    /**
     * @brief postorderTraversal
     */
    void postorderTraversal() const;

    /**
     * @brief buildBinaryTree
     */
    void buildBinaryTree();

    /**
     * @brief evaluateTree
     * @return
     */
    numv evaluateTree();

    /**
     * @brief built
     * @param expression
     * @return
     */
    contentType built(string expression);

    /**
     * @brief setCurrentSS
     * @param m
     */
    void setCurrentSS(matrix *m);

    /**
     * @brief setCurrentC
     * @param c
     */
    void setCurrentC(cell *c);

private:
    /**
       * @brief inorder
       * @param p
       */
    void inorder(node *p) const;

    /**
     * @brief preorder
     * @param p
     */
    void preorder(node *p) const;

    /**
     * @brief postorder
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
    matrix   *currentMatrix;
    cell     *currentCell;
};

#endif // SYNTAXTREE_H
