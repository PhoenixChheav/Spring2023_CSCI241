//********************************************************************
//
// main.cpp
// CSCI 241 Assignment 4
//
// Created by Leang Y Chheav (z-id: Z1966108)
// and Sam Normoyle (z-id: Z1980761)
//********************************************************************

#include "simplesim.h"
#include "sml.h"

/**
 * Attempts to load and execute an SML program read from standard
 * input, and then dumps the contents of the simplesim's registers
 * and memory.
 *
 * @return Zero on successful completion; otherwise, a non-zero
 *         return code.
 */
int main()
{
    simplesim s;    // Define a simplesim object.

    // Try to load SML program into the simplesim's memory. If
    // successful, execute the program.
    if (s.load_program())
        s.execute_program();

    // Dump the contents of the simplesim's registers and memory.
    s.dump();

    return 0;
}
