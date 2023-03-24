#include "mystack.h"
#include <cstdlib>
//*************************************************************************
//
//  mystack.cpp
//  CSCI 241 Assignment 7
//
//  Created by Leang Y Chheav (z1966108) and Sam Normoyle (z-id: Z1980761)
//
//*************************************************************************

/****
 * mystack() default constructor
*/
mystack::mystack(){
    stack_cap = 0;
    stack_size = 0;
    stack_array = new char[stack_cap];
}

/****
 * mystack(const mystack& x): copy constructor
 * @param x: object of the "mystack" data member
 * 
 * The stack size for the new object should be equal to the stack size of the object x.
 * 
 * The stack capacity for the new object should be equal to the stack capacity of the object x.
 * 
 * If the stack capacity is 0, the stack array pointer for the new object should be nullptr.
 * Otherwise, the stack array pointer should point to an array of char with a number of elements equal to the stack capacity.
 * The array should contain the same values as the stack array of the object x.
 * The contents of any array elements that are not actually part of the stack are unimportant.
 * 
*/
mystack::mystack(const mystack& x){
    stack_cap = x.stack_cap;
    stack_size = x.stack_size;
    stack_array = new char[x.stack_cap];
    for(size_t i =0 ; i<stack_size; i++){
        stack_array[i] = x.stack_array[i];
    }
}

/****
 * ~mystack() the destructor that delete the stack array
 * @param  function tke no parameter
 * @return no return
*/
mystack::~mystack(){
    delete[] stack_array;
}

/****
 * This overloaded copy assignment operator should assign one mystack object (the object x)
 * to another (the object that called the member function, which is pointed to by this).
 * The state of the data members when the function ends should be same as described above for the copy constructor.
 * 
 * @param x mystack object
 * @return this object pointer
*/
mystack& mystack::operator=(const mystack& x){
    if(this != &x){
        delete[] stack_array;

        stack_cap = x.stack_cap;
        stack_size = x.stack_size;
        if(stack_cap == 0){
            stack_array = nullptr;
        }
        else{
            stack_array = new char[stack_cap];
            for(size_t i = 0; i < stack_size; i++){
            stack_array[i] = x.stack_array[i];
            }
        }

       
    }
    return *this;
}

/****
 * capacity() const
 * take no parameter
 * @return the stack capacity
*/
size_t mystack::capacity() const {
    return stack_cap;
}

/****
 * size() const
 * take no parameters
 * @return the stack size
*/
size_t mystack::size() const{
    return stack_size;
}

/****
 * empty() const
 * take no parameter
 * @return 'true' if the stack size is 0, if not return 'false'
*/
bool mystack::empty() const{
    return(stack_size == 0);
}

/****
 * clear() the function to set the stack size back to 0
 * take no parameter
 * @return no return
*/
void mystack::clear(){
    stack_size = 0;
}

/****
 * reserve(size_t n) modifies an object's stack capacity without changing the stack size or the content of the stack array
 * 
 * @param n size of the stack capacity
 * 
 * @return no return
 * 
 * LOGIC
 * If n is less than the stack size or n is equal to the current stack capacity, simply return.
    Set the stack capacity to n.
    Declare a temporary array pointer (a pointer to an char).
    Use the temporary array pointer to dynamically allocate an array of char. The number of elements in the new temporary array should be equal to the stack capacity.
    Copy the contents of the stack array into the temporary array.
    Delete the stack array.
    Set the stack array pointer to the temporary array pointer.
****/
void mystack::reserve(size_t n){
    if(n <= stack_cap){
        return;
    }
    stack_cap = n;
    //Allocate a new array of size n called temp_array
    char *temp_array = new char[n];
    //Copy the contents of stack_array into temp_array
    for(size_t i = 0; i < n; i++){
        temp_array[i] = stack_array[i];
    }

    //delete the stack_array
    delete[] stack_array;
    
   
    stack_array = temp_array;
     
}

/****
 * top() const
 * DON'T call this function if stack is empty
 * take no parameter
 * @return the top item in the stack
****/
const char& mystack::top() const{
    return stack_array[stack_size - 1];
}

/****
 * push(char value) push the character value onto the top of the stack
 * 
 * @param value the value of item to insert
 * 
 * @return no return
 * 
 * LOGIC
 * If the stack size is equal to the stack capacity, the reserve() function will need to be called to increase the stack's capacity. If the current capacity is 0, the capacity should be increased to 1. Otherwise, the current capacity should be doubled.
    Copy value into the stack array as the new top item in the stack.
    Increase the stack size by 1.
 * 
*/
void mystack::push(char value){
    //if stack is full, reserve additional storage
    if(stack_size == stack_cap){
        if(stack_cap == 0){
            reserve(1);
        }else{
            reserve(stack_cap * 2);
        }
    }
    //insert value into stack array and increment stack size
    stack_array[stack_size] = value;
    stack_size++;
}

/****
 * pop() pop the top item off of the stack by decreasing the stack size by 1.
 * DON'T called if the stack is empty.
 * 
 * take no parameter
 * 
 * @return no return
****/
void mystack::pop(){
    stack_size--;
}