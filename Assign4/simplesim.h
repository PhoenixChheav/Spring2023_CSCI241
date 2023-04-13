#ifndef SIMPLESIM_H
#define SIMPLESIM_H
//********************************************************************
//
// simplesim.h
// CSCI 241 Assignment 4
//
// Created by Leang Y Chheav (z-id: Z1966108)
// and Sam Normoyle (z-id: Z1980761)
//********************************************************************

class simplesim
{
    // Simplesim memory.
    int memory[100];

    // Simplesim registers.
    int accumulator;
    int instruction_counter;
    int instruction_register;
    int operation_code;
    int operand;

public:

    simplesim();
    bool load_program();
    void execute_program();
    void dump() const;
};

#endif
