//*************************************************************************
//
//  matrix.cpp
//  CSCI 241 Assignment 6
//
//  Created by Leang Y Chheav (z1966108) and Sam Normoyle (z-id: Z1980761)
//
//*************************************************************************

#include "matrix.h"

//defaul constructor that populates the matrix with the identity matrix
matrix::matrix(){
  matrix_array[0][0] = 1;
  matrix_array[0][1] = 0;
  matrix_array[1][0] = 0;
  matrix_array[1][1] = 1;
}

//construtor that populates the memeber array with the values of a passed matrix
matrix::matrix(int array[][2]){
  matrix_array[0][0] = array[0][0];
  matrix_array[0][1] = array[0][1];
  matrix_array[1][0] = array[1][0];
  matrix_array[1][1] = array[1][1];

}

/*************************************************
 * Calculates the determinant of a matrix
 *
 * @param none.
 *
 * @return Returns the value of integer determinant of the matrix.
 *************************************************/
int matrix::determinant() const{
  return matrix_array[0][0] * matrix_array[1][1] - matrix_array[0][1] * matrix_array[1][0];
}

/*************************************************
 * Adds two matrices together
 *
 * @param rhs a reference to a constant matrix object.
 *
 * @return Returns a result matrix that is the result of the addtion between 2 matrices.
 *************************************************/
matrix matrix::operator+(const matrix& rhs) const{
  matrix result;
  result.matrix_array[0][0] = this->matrix_array[0][0] + rhs.matrix_array[0][0];
  result.matrix_array[0][1] = this->matrix_array[0][1] + rhs.matrix_array[0][1];
  result.matrix_array[1][0] = this->matrix_array[1][0] + rhs.matrix_array[1][0];
  result.matrix_array[1][1] = this->matrix_array[1][1] + rhs.matrix_array[1][1];
  return result;
}

/*************************************************
 * Calculates the result of the scalar multiplication of an array.
 *
 * @param rhs integer that is the scalar.
 *
 * @return Returns the multiplcation of matrix.
 *************************************************/
matrix matrix :: operator*(int rhs) const{
  matrix result;
  result.matrix_array[0][0] = this->matrix_array[0][0] * rhs;
  result.matrix_array[0][1] = this->matrix_array[0][1] * rhs;
  result.matrix_array[1][0] = this->matrix_array[1][0] * rhs;
  result.matrix_array[1][1] = this->matrix_array[1][1] * rhs;
  return result;
}

/***********************************************************************
 * Calculates the resulting matrix from a multiplication of 2 matricies
 *
 * @param rhs reference to a constant matrix object.
 *
 * @return Returns the resulting matrix from the multiplication of the 2 matrices.
 ***********************************************************************/
matrix matrix:: operator*(const matrix& rhs) const{
  matrix result;
  result.matrix_array[0][0] = this->matrix_array[0][0] * rhs.matrix_array[0][0] + matrix_array[0][1] * rhs.matrix_array[1][0];
  result.matrix_array[0][1] = this->matrix_array[0][0] * rhs.matrix_array[0][1] + matrix_array[0][1] * rhs.matrix_array[1][1];
  result.matrix_array[1][0] = this->matrix_array[1][0] * rhs.matrix_array[0][0] + matrix_array[1][1] * rhs.matrix_array[1][0];
  result.matrix_array[1][1] = this->matrix_array[1][0] * rhs.matrix_array[0][1] + matrix_array[1][1] * rhs.matrix_array[1][1];
  return result;
}

/************************************************************************
 * Compares two arrays to see if they are equal
 *
 * @param rhs reference to a constant matrix object.
 *
 * @return Returns true if the arrays are the same. False if they are not.
 ************************************************************************/
bool matrix::operator==(const matrix& rhs) const{
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(this->matrix_array[i][j]==rhs.matrix_array[i][j]){
                return true;
            }
        }
        
    }
  return false;
}

/**************************************************
 * Compares two arrays to see if they are not equal
 *
 * @param rhs reference to a constant matrix object.
 *
 * @return Returns false if the arrays are the same. True if they are not.
 **************************************************/
bool matrix::operator!=(const matrix& rhs) const{
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(this->matrix_array[i][j] == rhs.matrix_array[i][j]){
                return false;
            }
        }
        
    }
  return true;
}

/********************************************
 * Compares two arrays
 *
 * @param os reference to an ostream object, representing the left operand of the stream insertion expression.
 * @param rhs reference to a constant matrix object, representing the right operand of the expression.
 *
 * @return  A reference to an ostream object.
 ********************************************/
std::ostream& operator<<(std::ostream& os, const matrix& rhs){
    os<< "[[" << rhs.matrix_array[0][0]<<", " << rhs.matrix_array[0][1]<< "], [" << rhs.matrix_array[1][0] << ", " <<rhs.matrix_array[1][1] << "]]";
  return os;
}

/*********************************
 * multiply a scalar by a matrix 
 *
 * @param an integer lhs and a reference to a constant matrix object rhs.
 *
 * @return The result of multiplying the elements of the matrix right operand by the integer left operand
 *********************************/
matrix operator*(int lhs, const matrix& rhs){
  matrix result;
  result.matrix_array[0][0] = lhs * rhs.matrix_array[0][0];
  result.matrix_array[0][1] = lhs * rhs.matrix_array[0][1];
  result.matrix_array[1][0] = lhs * rhs.matrix_array[1][0];
  result.matrix_array[1][1] = lhs * rhs.matrix_array[1][1];

  return result;
}