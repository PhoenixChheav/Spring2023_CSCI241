#ifndef INPOST_H
#define INPOST_H
#include <string>

//*************************************************************************
//
//  inpost.h
//  CSCI 241 Assignment 7
//
//  Created by Leang Y Chheav (z1966108) and Sam Normoyle (z-id: Z1980761)
//
//*************************************************************************

using namespace std;
string convert(const string& infix);
int precedence(char op);

#endif