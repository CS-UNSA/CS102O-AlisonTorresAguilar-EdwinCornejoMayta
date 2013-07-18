#include "evaluator.h"

evaluator::evaluator(){

    operation["+"]=&evaluator::add;
    operation["-"]=&evaluator::sub;
    operation["*"]=&evaluator::mul;
    operation["/"]=&evaluator::div;
    operation["%"]=&evaluator::mod;
    function["sin"]=&evaluator::sin_;
    function["cos"]=&evaluator::cos_;
    function["tag"]=&evaluator::tag_;
    function["ctg"]=&evaluator::ctg_;
    function["sec"]=&evaluator::sec_;
    function["csc"]=&evaluator::csc_;
    function["csc"]=&evaluator::abs_;
}

 double evaluator::add(numv a,numv b){
    return (a+b);
    }

numv evaluator::sub(numv a,numv b){
    return (a-b);
    }

numv evaluator::mul(numv a,numv b){
    return (a*b);
    }

numv evaluator::div(numv a,numv b){
    if(b==0)
        throw "Division by zero condition!";
    return (a/b);
    }

numv evaluator::mod(numv a,numv b){
    return ((int)a%(int)b);
    }

numv evaluator::sin_(numv a){
    return sin(a);
    }

numv evaluator::cos_(numv a){
    return cos(a);
    }

numv evaluator::tag_(numv a){
    return tan(a);
    }

numv evaluator::ctg_(numv a){
    return 1.0/(tan(a));
    }

numv evaluator::sec_(numv a){
    return 1.0/(cos(a));
    }

numv evaluator::csc_(numv a){
    return 1.0/(sin(a));
    }

numv evaluator::abs_(numv a){
    return a>=0?a:-a;
    }
numv evaluator::evaluar(numv a,numv b,oprv op){
    return (this->*operation[op])(a,b);
    }
numv evaluator::evaluar(numv a,oprv op){
    return (this->*function[op])(a);
    }
