#include "syntaxtree.h"
#include "parser.h"
void syntaxTree::built(string expression){
    parser parseTree;
    parseTree.getTokens();
    parseTree.toPostfix();
    outputList=parseTree.getOutputList();
    buildBinaryTree();
}
void syntaxTree::buildBinaryTree(){
   eval =new evaluator();
    stack<node*> auxStack;

    token t;
    tokenValue t_value="";
    tokenType  t_type=NONE;

    nodeCell * cell;
    nodeNumber * number;
    nodeOperation * operation;


    while(!outputList.empty()){
        t=outputList.front();//sacar valor
        t_type=t.type;
        t_value=t.value;

        switch(t_type){
        case NUMBER:{
            number =new nodeNumber();
            number->setValue(t_value);
            auxStack.push(number);
            number++;
            break;
            }
        case VARIABLE:{

            cell = new nodeCell();
            cell->setValue(t_value);

            auxStack.push(cell);
            break;
            }
        case OPERATOR:{
            operation = new nodeOperation();
            operation->setValue(t_value);
            operation->setLeft(*auxStack.top());
            auxStack.pop();
            operation->setRight(*auxStack.top());
            auxStack.pop();
            auxStack.push(operation);
            operation++;
            break;
            }
        case FUNCTION:{
            operation= new nodeOperation();
            operation->setValue(t_value);
            operation->setLeft(*auxStack.top());
            auxStack.pop();
            auxStack.push(operation);
            operation++;
            break;
            }
        default:
            cout<<"there is an error"<<endl;
            break;
        }
        outputList.pop_front();
    }
    root=auxStack.top();
}


void syntaxTree::insert(const node& itemToInsert){

}

void syntaxTree::inorder(node *p) const{
    if (p != NULL)
        {
            inorder(p->getLeft());
            p->print();
            inorder(p->getRight());
        }
}
void syntaxTree::preorder(node *p) const{
    if (p != NULL)
        {
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
        }
}

numv syntaxTree::evaluate(node *p)const{

    if(p->isLeaft())
        return *(numv*)p->getValue();
    else if(p->isUnary())
        return   eval->evaluar(evaluate(p->getLeft()),*(oprv*)p->getValue());
        //return  3;
    else if (p->isBinary())
        return eval->evaluar(evaluate(p->getLeft()), evaluate(p->getRight()),*(oprv*)p->getValue());
        //return  8;
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

numv syntaxTree::evaluateTree() {
    return evaluate(root);
}
