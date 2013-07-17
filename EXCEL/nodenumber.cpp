#include "nodenumber.h"

nodeNumber::nodeNumber(){
}

void nodeNumber::print(){
    cout<<value<<endl;
}

void* nodeNumber::getValue(){
    return &value;
}

 void nodeNumber::setValue(nodev v){
     value=toNumv(v);
 }

 numv nodeNumber::toNumv( string s ){
     numv  n;
     stringstream ss( s );
     ss>>n;
     return n;
 }
