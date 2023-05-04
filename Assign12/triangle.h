//***************************************************************
//
//  triangle.h
//  CSCI 241 Assignment 12
//
//  Created by Phoenix Chheav (z1966108) and Sam Normoyle (z-id: Z1980761)
//
//***************************************************************

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class triangle:public shape{
    private:
        int height = 0;
        int base = 0;

    public:
        triangle(const string&, int, int);
        void print() const;
        double get_area() const;
};

#endif