#include "nodeoperation.h"

nodeOperation::nodeOperation(){
}

void nodeOperation::print(){
    cout<<value<<endl;
}

void* nodeOperation::getValue(){
    return &value;
}
 void nodeOperation::setValue(oprv v){
     value=v;
 }
