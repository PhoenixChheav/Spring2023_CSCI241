//***************************************************************
//
//  triangle.cpp
//  CSCI 241 Assignment 12
//
//  Created by Phoenix Chheav (z1966108) and Sam Normoyle (z-id: Z1980761)
//
//***************************************************************

#include "shape.h"
#include "triangle.h"

/**
 * @brief Construct a new triangle::triangle object
 * 
 * @param color 
 * @param height 
 * @param base 
 */
triangle::triangle(const string& color, int height, int base): shape(color), height(height), base(base)
{
}

/**
 * @brief print the color, shape, height, base and area
 * 
 */
void triangle::print() const{
    shape::print();
    cout << "triangle, height " << height << ", base " << base << ", area " << get_area() << endl;
}

/**
 * @brief get_area(): calculate the area of the triangle
 * 
 * @return area
 */
double triangle::get_area() const{
    double area = 0.5 * base * height;
    return area;
}