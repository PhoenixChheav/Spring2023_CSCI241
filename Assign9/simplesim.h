#ifndef SIMPLESIM_H
#define SIMPLESIM_H
//********************************************************************
//
// simplesim.h
// CSCI 241 Assignment 9
//
// Created by Leang Y Chheav (z-id: Z1966108)
// and Sam Normoyle (z-id: Z1980761)
//********************************************************************

class simplesim
{
    // Simplesim memory.
    int memory[100];

    // Simplesim registers.
    int accumulator = 0;
    int instruction_counter = 0;
    int instruction_register = 0;
    int operation_code = 0;
    int operand = 0;

public:

    simplesim();
    bool load_program();
    void execute_program();
    void dump() const;
};

#endif
