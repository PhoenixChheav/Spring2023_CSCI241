//***************************************************************
//
//  rectangle.cpp
//  CSCI 241 Assignment 12
//
//  Created by Phoenix Chheav (z1966108) and Sam Normoyle (z-id: Z1980761)
//
//***************************************************************

#include "rectangle.h"

/**
 * @brief constructor
 * 
 * @param color 
 * @param height 
 * @param width 
 */
rectangle::rectangle(const string& color, int height, int width):shape(color),height(height), width(width)   
{
}

/**
 * @brief print the color, shape, height, width and area
 * 
 */
void rectangle::print() const{
    shape::print();
    cout << "rectangle, height " << height << ", width " << width << ", area " << get_area() << endl;
}

/**
 * @brief get_area(): calculate the area of the rectangle
 * 
 * @return area
 */
double rectangle::get_area() const{
    double area = height * width;
    return area;
}
