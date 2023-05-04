//***************************************************************
//
//  circle.cpp
//  CSCI 241 Assignment 12
//
//  Created by Phoenix Chheav (z1966108) and Sam Normoyle (z-id: Z1980761)
//
//***************************************************************

#include "circle.h"
#include <cmath>

/**
 * @brief Construct a new circle
 * 
 * @param color color of the circle
 * @param radius radius of the circle
 */
circle::circle(const string& color, int radius) : shape(color), radius(radius){

}

/**
 * @brief Print the color, radius and area of the circle
 * 
 */
void circle::print() const{
    shape::print();
    cout << "circle, radius " << radius << ", area " << get_area() << endl;
}

/**
 * @brief get_area() - calculate the area
 * 
 * @return double 
 */
double circle::get_area() const{
    double area = M_PI *(double)radius * (double)radius;
    return area;
}