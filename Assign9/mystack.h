#ifndef MYSTACK_H
#define MYSTACK_H

//*************************************************************************
//
//  mystack.h
//  CSCI 241 Assignment 9
//
//  Created by Leang Y Chheav (z1966108) and Sam Normoyle (z-id: Z1980761)
//
//*************************************************************************

#include <cstdlib>

class mystack{

    private:
        char *stack_array;
        size_t stack_cap;
        size_t stack_size;
    public:
        mystack();
        mystack(const mystack& x);
        ~mystack();
        mystack& operator=(const mystack& x);
        size_t capacity() const;
        size_t size() const;
        bool empty() const;
        void clear();
        void reserve(size_t n);
        const char& top() const;
        void push(char value);
        void pop();

};

#endif