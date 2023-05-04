//*************************************************************************
//
//  mystack.cpp
//
//  CSCI 241 Assignment 8
//
//  Created by Leang Y Chheav (z1966108) and Sam Normoyle (z-id: Z1980761)
//
//*************************************************************************

#include "mystack.h"

/****
 * mystack() default constructor
****/
mystack::mystack(){
    stk_top = nullptr;
    stk_size = 0;
}

/****
 * mystack(const mystack& x): copy constructor
 * 
 * @param x: reference to a constant stack
 * 
 * @return function take no return
 * 
****/
mystack::mystack(const mystack& x){
    //set the new stack object's list to empty
    stk_top = nullptr;

    //Copy the other stack's size
    stk_size = x.stk_size;
    //copy the other stack's linked list'
    clone(x);
}

/***
 * Destructor: call the clear() member function
 * 
 * @param no take no parameter
 * 
 * @return no return
*/
mystack::~mystack(){
    clear();
}

/***
 * operator=(const mystack& x) : copy assignment operator
 * 
 * @param x: reference to a constant stack
 * 
 * @return the member function pointed by *this
***/
mystack& mystack::operator=(const mystack& x){
    if(this != &x){
        //make the left stack object empty
        clear();

        //copy the other stack's size
        stk_size = x.stk_size;

        //copy the other stack's linked list
        clone(x);
    }
    return *this;
}

/***
 * size_t size()
 * @param function take no param
 * 
 * @return stk_size: stack size
***/
size_t mystack::size() const{
    return stk_size;
}

/***
 * bool empty() : empty the stack
 * 
 * @param function takes no param
 * 
 * @return true if the stack size is empty
 *          false if the stack size is not empty
***/
bool mystack::empty() const{
    if(stk_size == 0){
        return true;
    }
    return false;
}

/***
 * void clear() : delete all nodes in the stack's linked list and set the size back to 0
 * 
 * @param function takes no param
 * 
 * @return no return
***/
void mystack::clear(){
    //while it's not empty pop()
    // while(!empty()){
    //     pop();
    // } or if size is not 0
    while(stk_size != 0){
        pop();
    }
}

/***
 * const int& top() : assgin the value to the top node stack
 * 
 * @param functions takes no param
 * 
 * @return value in the top node of stack
***/
const int& mystack::top() const{
    return stk_top->value;
}

/***
 * void push(int value): push the value onto the top of the stack
 * 
 * @param value as integer
 * 
 * @return no return
***/
void mystack::push(int value){
    //Allocate a new stack node, new_node;
    node *new_node = new node(value, stk_top);
   
    stk_top = new_node;
    stk_size++;
}

/***
 * void pop() : pop the item off the stack and delete the node that contain it
 * 
 * @param function takes no param
 * 
 * @return no return
***/
void mystack::pop(){
    node* delete_node = stk_top;
    stk_top = stk_top -> next;
    delete delete_node;
    stk_size--;

}

/***
 * void clone(const mystack& x) : Copy linked list from the stack x to this object
 * 
 * @param x: reference to a constant stack
 * 
 * @return function takes no return
***/
void mystack::clone(const mystack& x){
    node* last = nullptr;
    node* ptr = x.stk_top;

    while(ptr != nullptr){
        //allocate a new stack node, new node
        node *new_node = new node(0, ptr);
        //new_node-> value = ptr-> value;

        if(last == nullptr){
            stk_top = new_node;
        }else{
            last->next = new_node;
        }
        last = new_node;
        ptr = ptr->next;
    }

}

