#include "syntaxtree.h"

void syntaxTree::insert(const int& insertItem)
{
    node *current;  //pointer to traverse the tree
    node *trailCurrent; //pointer behind current
    node *newNode;  //pointer to create the node

    newNode = new node;
    assert(newNode != NULL);
    //newNode->value = insertItem;
    //newNode->leftchild = NULL;
    //newNode->rightchild = NULL;
/*
    if (root == NULL)
        root = newNode;
    else
    {
        current = root;

        while (current != NULL)
        {
            trailCurrent = current;

            if (current->info == insertItem)
            {
                cerr << "The insert item is already in the list-";
                cerr << "duplicates are not allowed."
                     << insertItem << endl;
                return;
            }
            else if (current->info > insertItem)
                current = current->llink;
            else
                current = current->rlink;
        }//end while

        if (trailCurrent->info > insertItem)
            trailCurrent->llink = newNode;
        else
            trailCurrent->rlink = newNode;
    }
    */
}//end insert
