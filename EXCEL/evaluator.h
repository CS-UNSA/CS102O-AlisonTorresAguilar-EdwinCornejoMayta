#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "definedtypes.h"

class evaluator
{
public:

    typedef numv (evaluator::*ope)( numv, numv) ;
    typedef numv (evaluator::*fun)( numv) ;

    evaluator();
    map<string,ope> operation;
    map<string,fun> function;

    numv add(numv a,numv b);
    numv sub(numv a,numv b);
    numv mul(numv a,numv b);
    numv div(numv a,numv b);
    numv mod(numv a,numv b);
    numv sin_(numv a);
    numv cos_(numv a);
    numv tag_(numv a);
    numv ctg_(numv a);
    numv sec_(numv a);
    numv csc_(numv a);
    numv abs_(numv a);
    numv sqrt_(numv a,numv);

    numv evaluar(numv a,numv b,oprv op);
    numv evaluar(numv a,oprv op);
};

#endif // EVALUATOR_H
