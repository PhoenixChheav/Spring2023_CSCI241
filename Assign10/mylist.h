//*******************************************************************
// 
//  mylist.h
//  CSCI 241 Assignment 10
//
//  Created by Phoenix Chheav (z1966108) and Sam Normoyle (z-id: Z1980761)
//
//*******************************************************************

#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <stdexcept>
using namespace std;
template <class T>
class mylist;

template <class T>
std::ostream &operator<<(std::ostream &, const mylist<T> &);
template <class T>
struct node{
    T value;
    node<T>* prev;
    node<T>* next;

    node (const T& value = T(), node<T>* prev = nullptr, node<T>* next = nullptr){
    this->value = value;
    this->prev = prev;
    this->next = next;
    }
};

//forward declaration of the mylist template class
template <class T>
class mylist{
    //friend declaration for the template function - note the special syntax
    friend std::ostream& operator<< <>(std::ostream&, const mylist<T>&);

    private:
        node<T>* l_front;
        node<T>* l_back;
        size_t lsize;
        void clone(const mylist<T>&);

    public:
        mylist(); //constructor
        ~mylist(); //destructor
        mylist(const mylist<T>&); //copy consrtuctor
        mylist<T>& operator=(const mylist<T>&x); //overload operator
        void clear();
        size_t size() const;
        bool empty() const;
        const T& front() const;
        T& front();
        const T& back() const;
        T& back();
        void push_front(const T&);
        void push_back(const T&);
        void pop_front();
        void pop_back();
        bool operator==(const mylist<T>&) const;
        bool operator<(const mylist<T>&) const;

};

//Forward declaration of the operator<< template function

//function definitions for the mylist class
template <class T>
mylist<T>::mylist(){
    l_front = nullptr;
    l_back = nullptr;
    lsize = 0;
}

/**
 * @brief Destroy the mylist<T>::mylist object
 * 
 * @tparam T 
 */
template <class T>
mylist<T>::~mylist(){
    clear();
}

/**
 * @brief Construct a new mylist<T>::mylist object
 * 
 * @tparam T 
 * @param x 
 */
template <class T>
mylist<T>::mylist(const mylist<T>& x){
    clear();
    clone(x);
}

/**
 * @brief operator=(const mylist<T>& x): copy assignment operator
 * 
 * @tparam T 
 * @param x object of class T
 * @return mylist<T> 
 */
template <class T>
mylist<T> &mylist<T>::operator=(const mylist<T> &x){
    if(this != &x){
        //make the left stack object empty
        clear();

        //copy the other stack's size
        //size = x.size;

        //copy the other stack's linked list
        clone(x);
    }
    return *this;   
}

/**
 * @brief clear(): set the list back to the empty state
 * 
 * @tparam T 
 */
template <class T>
void mylist<T>::clear(){
    while(lsize != 0){
        pop_back();
    }
}

/**
 * @brief size(): return the list size
 * 
 * @tparam T 
 * @return size: the size of the list 
 */
template <class T>
size_t mylist<T>::size() const{
    return lsize;
}



/**
 * @brief This function returns true if the list is empty
 * 
 * @return true 
 * @return false 
 */
template <class T>
bool mylist<T>::empty() const{
    if(lsize == 0){
        return true;
    }
    return false;
}

/**
 * @brief front(): return the value of the front of the list
 * 
 * @tparam T 
 * @return the value of the front
 */
template <class T>
const T& mylist<T>::front() const{
    if(empty()){
        throw underflow_error("underflow exception on call to front()");
    }
    return l_front->value;
}
template <class T>
T& mylist<T>::front(){
     if(empty()){
        throw underflow_error("underflow exception on call to front()");
    }
    return l_front->value;
}

/**
 * @brief back(): return the value of the back of the list
 * 
 * @tparam T 
 * @return value of the back of the list
 */
template <class T>
const T& mylist<T>::back() const{
    if(empty()){
        throw underflow_error("underflow exception on call to back()");
    }
    return l_back->value;
}
template <class T>
T& mylist<T>::back(){
    if(empty()){
        throw underflow_error("underflow exception on call to back()");
    }
    return l_back->value;    
}

/**
 * @brief push_front(const &T value) insert the item at the front of the list
 * 
 * @tparam T 
 * @param value value of the item to be push
 */
template <class T>
void mylist<T>::push_front(const T& value){

    node<T> *new_node = new node<T>(value);

    new_node->next = l_front; // point to new node's prev pointer at current last node in the list
    if(empty()){//if it's empty
        l_back = new_node;
    }else{
        l_front->prev = new_node; // point current last node's next pointer at new
    } 
    l_front = new_node; //point l_back at new last node in the list   
    lsize++;
}

/**
 * @brief push_back(const &T value) insert the item at the back of the list
 * 
 * @tparam T 
 * @param value value of the item to be push
 */
template <class T>
void mylist<T>::push_back(const T& value){
    
    node<T> *new_node = new node<T>(value);

    new_node->prev = l_back; // point to new node's prev pointer at current last node in the list
    if(empty()){//if it's not empty
        l_front = new_node;
    }else{
        l_back->next = new_node; // point current last node's next pointer at new
    }
    l_back = new_node; //point l_back at new last node in the list
    lsize++;
}

/**
 * @brief remove item at the front of the list
 * 
 * @tparam T 
 */
template <class T>
void mylist<T>:: pop_front(){

    if(empty()){
        throw underflow_error("underflow exception on call to pop_front()");
    }

    node<T>* del_node = l_front; //save address of node to delete in a pointer
    l_front = del_node->next; // point l_back at the new last node in the list
    if(l_front == nullptr){// if there's only one node
        l_back = nullptr;
    }else{
        l_front->prev = nullptr; // set the new lsat node's next pointer to nullptr
    
    }
    delete del_node;
    lsize--;
}

/**
 * @brief remove item at the back of the list
 * 
 * @tparam T 
 */
template <class T>
void mylist<T>:: pop_back(){

    if(empty()){
        throw underflow_error("underflow exception on call to pop_back()");
    }

    node<T>* del_node = l_back; //save address of node to delete in a pointer
    l_back = del_node->prev; // point l_back at the new last node in the list
    if(l_back == nullptr){// if there's only one node
        l_front = nullptr;
    }else{
        l_back->next = nullptr; // set the new lsat node's next pointer to nullptr
    
    }
    delete del_node;
    lsize--;
}
/**
 * @brief compares two lists and if they are the same returns true flase if they are different
 * 
 * @tparam T 
 * @param rhs right hand side
 * @return true 
 * @return false 
 */
template <class T>
bool mylist<T>::operator==(const mylist<T>& rhs) const{
    if(rhs.lsize != lsize){
        return false;
    }

    node<T> *ptr = l_front;
    node<T> * rightptr = rhs.l_front;
    while( ptr != nullptr && rightptr != nullptr){

        if(ptr->value != rightptr->value){
            return false;
        }
        ptr = ptr -> next;
        rightptr = rightptr ->next;
    }
    return true;
}
/**
 * @brief Compares two lists to see if the left hand side is less than the right handside
 * if it is less it returns true if it is not it returns false.
 * 
 * @tparam T 
 * @param rhs 
 * @return true 
 * @return false 
 */
template <class T>
bool mylist<T>::operator<(const mylist<T>& rhs) const{
    
    
    node<T> * rightptr = rhs.l_front;
    node<T> *ptr = l_front;

    while( ptr != nullptr && rightptr != nullptr){
        if(ptr->value < rightptr->value){
            return true;
        }
        else if(ptr -> value > rightptr-> value){
            return false;
        }
        rightptr = rightptr ->next;
        ptr = ptr -> next; 
    }
    return(lsize < rhs.lsize)? true : false;       
}
/**
 * @brief prints out the entire mylist object so it can be sent to standard output.
 * 
 * @tparam T 
 * @param os object
 * @param obj mylist<T> obj
 * @return std::ostream& 
 */
template <class T>
std::ostream& operator<<(std::ostream& os, const mylist<T>& obj){
    for(node<T> *ptr = obj.l_front; ptr != nullptr; ptr = ptr->next){
        os << ptr->value << " "; 
    }
    return os;
}

/************************************************************
 * copies a mylist to another mylist
 * @param x mylist to clone from
 ************************************************************/
template <class T>
void mylist<T>::clone(const mylist<T> &x)
{
    // Loop through each node and push it on
    for (node<T> *ptr = x.l_front; ptr != nullptr; ptr = ptr->next)
    {
        push_back(ptr->value);
    }
}


#endif