//*************************************************************************
//
//  mystack.h
//  CSCI 241 Assignment 8
//
//  Created by Leang Y Chheav (z1966108) and Sam Normoyle (z-id: Z1980761)
//
//*************************************************************************

#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
    node* next;
    int value;

    node(int value, node* next = nullptr){
        this -> value = value;
        this -> next = next;
    }
};

class mystack{
    private:
        node* stk_top = nullptr;
        size_t stk_size;
    public:
        mystack();
        mystack(const mystack& x);
        ~mystack();
        mystack& operator=(const mystack& x);
        size_t size() const;
        bool empty() const;
        void clear();
        const int& top() const;
        void push(int value);
        void pop();
        void clone(const mystack& x);
};

#endif