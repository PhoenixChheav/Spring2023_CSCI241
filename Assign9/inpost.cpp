#include <string>
#include <cctype>
#include "mystack.h"
#include "inpost.h"

//*************************************************************************
//
//  inpost.cpp
//  CSCI 241 Assignment 9
//
//  Created by Leang Y Chheav (z1966108) and Sam Normoyle (z-id: Z1980761)
//
//*************************************************************************


/***
 * convert(): convert the infix expression passed to it as a C++ string into an equivalent postfix expression stored in a string object.
 * Assume that 'infix' is a valid expression, only '(' and ')' will be used
 * All variable will be single characters in lower case, and all constant will be integers.
 * 
 * @param infix an infix string
 * 
 * @return postfix string
 * 
*/
string convert(const string& infix){
    string postfix;
    mystack stack;

    size_t index = 0;

    while(index < infix.length()){
        if(islower(infix[index])){
            postfix += infix[index];
            postfix += ' ';
            index++;
        }else if(isdigit(infix[index])){
            //This is literal
           
            postfix += infix[index];
            index++;
            if(!isdigit(infix[index])){
                postfix+= ' ';
            }
        }else if(isspace(infix[index])){
            index++;
        }else if(infix[index] == '('){
            //push infix[index] to stack
            stack.push(infix[index]);
            index++;
        }else if(infix[index] == ')'){
            //right parenthesis
            while(!stack.empty() && stack.top() != '('){
                postfix += stack.top();
                postfix += ' ';
                stack.pop();
            }
            if(!stack.empty()){
                stack.pop();
            }
            index++;
        }
            else{  
                while(!stack.empty() && precedence(infix[index]) <= precedence(stack.top())){
                    postfix += stack.top();
                    postfix += ' ';
                    stack.pop();
                    
                }
                stack.push(infix[index]);
                index++;
            
            }   
    }
    while(!stack.empty()){
        postfix += stack.top();
      
        stack.pop();
    if(!stack.empty())
          postfix += ' ';
    } 
    return postfix;
}

/**
 * @brief 
 * 
 * @param op 
 * @return int 
 */
int precedence(char op){

    switch(op){
        case '~':{
            return 3;
        }break;

        case '^':{
            return 3;
        }break;

        case '*':{
            return 2;
        }break;

        case '/':{
            return 2;
        }

        case '+':{
            return 1;
        }

        case '-':{
            return 1;
        }

        default:{
            return -1;
        }
    }
    return -1; 
}