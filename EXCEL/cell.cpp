#include "cell.h"

void cell::setExpression(string e){
}

string cell::getExpression(){}


void cell::addUsedBy(cell * p){
    usedBy.push_back(p);
}
