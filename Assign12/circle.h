//***************************************************************
//
//  circle.h
//  CSCI 241 Assignment 12
//
//  Created by Phoenix Chheav (z1966108) and Sam Normoyle (z-id: Z1980761)
//
//***************************************************************

#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <cstdlib>
#include "shape.h"

using namespace std;
class circle: public shape{
    private:
        int radius = 0;

    public:
        circle(const string&, int);
        void print() const;
        double get_area() const;
};


#endif //CIRCLE_H