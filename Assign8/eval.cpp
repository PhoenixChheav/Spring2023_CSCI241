//*************************************************************************
//
//  eval.cpp
//  CSCI 241 Assignment 8
//
//  Created by Leang Y Chheav (z1966108) and Sam Normoyle (z-id: Z1980761)
//
//*************************************************************************

/***
 * 
 * evaluate(const string& postfix): evaluate the postfix expression passed to it
 * 
 * @param postfix the expression that is passed to it
 * 
 * @return calculated value
 * 
***/
#include "eval.h"
#include "mystack.h"

int evaluate(const string& postfix){
    string op;
    stringstream ss(postfix);
    mystack eval_stack;
    int temp= 0;
    while (ss >> op){
        if(isdigit(op[0])){
            eval_stack.push(stoi(op));
        }
        else if(isalpha(op[0])){

            temp = op[0] - 'a';
            eval_stack.push(temp);
        }
        else if(op == "~"){
            temp = eval_stack.top()*-1;
            eval_stack.pop();
            eval_stack.push(temp);

        }
        else{
            int right = eval_stack.top();
            eval_stack.pop();
            int left = eval_stack.top();
            eval_stack.pop();

            if(op == "+"){
                eval_stack.push(left + right);
            }   
            if(op == "-"){
                eval_stack.push(left - right);                
            }
            if(op == "*"){
                eval_stack.push(left * right);                
            }        
            if(op == "/"){
                if(right == 0){
                    cout<<"*** Division by 0 ***" << endl;
                    eval_stack.push(0);
                }
                else{
                    eval_stack.push(left / right);  
                }
            
            } 
            if(op == "^"){
                eval_stack.push(pow(left,right));                
            }                           
        }
    }
    return eval_stack.top();
}