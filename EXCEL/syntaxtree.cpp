#include "syntaxtree.h"


void syntaxTree::buildBinaryTree(){

    stack<node*> auxStack;

    token t;
    tokenValue t_value="";
    tokenType  t_type=NONE;

    nodeCell cell;
    nodeNumber number;
    nodeOperation operation;

   int i =0;
    while(!outputList.empty()){
        t=outputList.front();//sacar valor
        t_type=t.type;
        t_value=t.value;

        switch(t_type){
        case NUMBER:
            if(auxStack.top()==NULL)
                cout<<"is null"<<endl;
            else
                cout<<"es raro"<<endl;
            number.setValue(t_value);
            auxStack.push(&number);
            cout<<"number"<<endl;
            //auxStack.top()->print();
            break;
        case VARIABLE:
            cell.setValue(t_value);
            auxStack.push(&cell);
            cout<<"variable"<<endl;

            break;

        case OPERATOR:

            auxStack.top()->print();
            operation.setValue(t_value);

            operation.setLeft(*auxStack.top());
            auxStack.pop();
            auxStack.top()->print();
            operation.setRight(*auxStack.top());
            auxStack.pop();
            cout<<"operation"<<endl;
            auxStack.push(&operation);

            break;

        case FUNCTION:
            auxStack.top()->print();
            operation.setValue(t_value);
            operation.setLeft(*auxStack.top());
            auxStack.pop();
            cout<<"function"<<endl;
            auxStack.push(&operation);
            auxStack.top()->print();
            break;

        }
        outputList.pop_front();
    }

    root=auxStack.top();



    cout<<"++++++++++++++++++++++++++++"<<endl;
    root->print();
    root->getLeft()->print();
    root->getRight()->print();
    //root->getLeft()->getRight()->print();
    cout<<"++++++++++++++++++++++++++++"<<endl;

}


void syntaxTree::insert(const node& itemToInsert){

}


void syntaxTree::inorder(node *p) const{
    if (p != NULL)
        {
            inorder(p->getLeft());
            p->print();
            cout<<"valor inorder"<<endl;
            inorder(p->getRight());
        }
}
void syntaxTree::preorder(node *p) const{
    if (p != NULL)
        {
            //cout<<p->info<<" ";
            p->print();
            preorder(p->getLeft());
            preorder(p->getRight());
        }

}

void syntaxTree::postorder(node *p)const{
    if (p != NULL)
        {
            postorder(p->getLeft());
            postorder(p->getRight());
            p->print();
            //cout << p->info << " ";
        }
}


void syntaxTree::inorderTraversal() const{
    inorder(root);
}

void syntaxTree::preorderTraversal() const{
    preorder(root);
}

void syntaxTree::postorderTraversal() const{
    postorder(root);
}
