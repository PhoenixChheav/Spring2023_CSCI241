//***************************************************************
//
//  shape.cpp
//  CSCI 241 Assignment 12
//
//  Created by Phoenix Chheav (z1966108) and Sam Normoyle (z-id: Z1980761)
//
//***************************************************************

#include "shape.h"

/**
 * @brief Construct a new shape
 * 
 * @param color 
 */
shape::shape(const string& color):color(color){
}

/**
 * @brief Destroy the shape
 * 
 */
shape::~shape(){}

/**
 * @brief Print the color
 * 
 */
void shape::print() const{
    cout << color << " ";
}




