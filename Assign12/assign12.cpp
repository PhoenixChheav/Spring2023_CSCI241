//***************************************************************
//
//  assign12.cpp
//  CSCI 241 Assignment 12
//
//  Created by Phoenix Chheav (z1966108) and Sam Normoyle (z-id: Z1980761)
//
//***************************************************************

#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include <vector>
#include <iomanip>


int main(){
    //declare a standard library of pointer to shape objects
    vector<shape*> shapes;

    //dynamically create shapes and add them into vector
    circle* circle1 = new circle("green", 10);
    shapes.push_back(circle1);

    rectangle* rectangle1 = new rectangle("red", 8, 6);
    shapes.push_back(rectangle1);

    triangle* triangle1 = new triangle("yellow", 8, 4);
    shapes.push_back(triangle1);

    triangle* triangle2 = new triangle("black", 4, 10);
    shapes.push_back(triangle2);

    circle* circle2 = new circle("orange", 5);
    shapes.push_back(circle2);

    rectangle* rectangle2 = new rectangle("blue", 3, 7);
    shapes.push_back(rectangle2);

    cout << "Printing all shapes..." << endl << endl;

    
    for(size_t i = 0; i < shapes.size(); i++){
        shapes[i]->print();
    }

   //loop through the array call and print() for each circle
    cout << endl << "Circle only:" << endl;
    for(size_t i = 0; i < shapes.size(); i++){
        circle* c = dynamic_cast<circle*>(shapes[i]);
        if(c != nullptr){
            c->print();
        }
    }

    for(size_t i = 0; i < shapes.size(); i++){
        shapes.pop_back();
    }
    

    return 0;
}