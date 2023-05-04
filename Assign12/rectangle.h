//***************************************************************
//
//  rectangle.h
//  CSCI 241 Assignment 12
//
//  Created by Phoenix Chheav (z1966108) and Sam Normoyle (z-id: Z1980761)
//
//***************************************************************

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class rectangle: public shape{
    private:
        int height = 0;
        int width = 0;

    public:
        rectangle(const string&, int, int);
        void print() const;
        double get_area() const;
};


#endif