//********************************************************************
//
// main.cpp
// CSCI 241 Assignment 5
//
// Created by Leang Y Chheav (z-id: Z1966108)
// and Sam Normoyle (z-id: Z1980761)
//********************************************************************
#include "account.h"
#include "bank.h"

int main(){
    bank b;
    b.read_account(accounts);
    b.print();
    b.process_transaction(transaction.txt);
    b.print();

    return 0;
}