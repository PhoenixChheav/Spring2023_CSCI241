//***************************************************************
//
//  shape.cpp
//  CSCI 241 Assignment 12
//
//  Created by Phoenix Chheav (z1966108) and Sam Normoyle (z-id: Z1980761)
//
//***************************************************************

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class shape{
    private:
        string color;
    
    public:
        shape(const string&);
        virtual ~shape();
        virtual void print() const;
        virtual double get_area() const = 0;
};


#endif