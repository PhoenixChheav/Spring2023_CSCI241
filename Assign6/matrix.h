#ifndef MATRIX_H
#define MATRIX_H

//*************************************************************************
//
//  matrix.h
//  CSCI 241 Assignment 6
//
//  Created by Leang Y Chheav (z1966108) and Sam Normoyle (z-id: Z1980761)
//
//*************************************************************************

#include <iostream>

class matrix{
    friend std::ostream& operator<<(std::ostream&, const matrix&);
    friend matrix operator*(int, const matrix&);

    private:
        int matrix_array[2][2];

    public:
        matrix(); //default constructor
        matrix(int [][2]);
        int determinant() const;
        matrix operator+(const matrix&) const;
        matrix operator*(int) const;
        matrix operator*(const matrix&) const;
        bool operator==(const matrix&) const;
        bool operator!=(const matrix&) const;



};

#endif