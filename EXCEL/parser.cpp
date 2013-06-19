#include "parser.h"

parser::parser()
{
    bufferSize=0;
}
void parser::getTokens(){
   bufferSize=buffer.length();
   token t;
   tokenValue t_value="";
   tokenType  t_type=NONE;
    for (unsigned int i=0;i<bufferSize;++i){
        if(isdigit(buffer[i])){
            t_value=buffer[i];
            while(i+1<bufferSize &&(isdigit(buffer[i+1]) || buffer[i+1]=='.')){
                ++i;
                t_value+=buffer[i];
            }
            t_type=NUMBER;
        }
        else if(isalpha(buffer[i])&&(t_type==NONE||t_type==OPERATOR||t_type==LPARENTHESIS)){
            t_value=buffer[i];

            while(i+1<bufferSize &&isalnum(buffer[i+1])){
                ++i;
                t_value+=buffer[i];

            }
            if(int(functions.find(t_value))!=-1)
            t_type=FUNCTION;
            else
            t_type=VARIABLE;
        }
        else if(buffer[i]=='('){
             t_value=buffer[i];
             t_type=LPARENTHESIS;
        }
        else if(buffer[i]==')'){
            t_value=buffer[i];
            t_type=RPARENTHESIS;
        }
        else if(int(functions.find(buffer[i]))!=-1) {
             t_value=buffer[i];
             t_type=OPERATOR;
        }
        else{
            cerr<< "error"<<endl;
            break;
        }

        t.value=t_value;
        t.value=t_type;
        tokenList.push_back(t);
        cout<<"t_value "<<t_value<<endl;
        cout<<"t_type "<<t_type<<endl;
        t_value="";


    }
}

void parser::toPostfix(){
    list<token>  outputList;
    stack<token> outputStack;
    token t;
    tokenValue t_value="";
    tokenType  t_type=NONE;


    while (!tokenList.empty()){
        t=*(tokenList.begin());//sacar valor
        t_type=t.type;

        switch (t_type){
        case NUMBER:
        case VARIABLE:
            outputList.push_back(t);
            break;
        case LPARENTHESIS:
            outputStack.push(t);
            break;
        case RPARENTHESIS:
            //outputStack.push(t);
            token stk;
            while (!outputStack.empty()&& (outputStack.top()).type!=LPARENTHESIS){
                    stk=outputStack.top();
                    outputList.push_back(stk);
                    outputStack.pop();
            }
            if ((outputStack.top()).type!=LPARENTHESIS)
                outputStack.pop();
            else
                cerr<<" error tipo 2";
            break;
        case OPERATOR:
             while (!outputStack.empty()&& (outputStack.top()).type=OPERATOR){

             }
             break;
        }

    }


}
