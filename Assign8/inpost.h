//*************************************************************************
//
//  inpost.h
//  CSCI 241 Assignment 8
//
//  Created by Leang Y Chheav (z1966108) and Sam Normoyle (z-id: Z1980761)
//
//*************************************************************************

#ifndef INPOST_H
#define INPOST_H

#include <string>
#include <sstream>


using namespace std;
string convert(const string& infix);
int precedence(char op);

#endif