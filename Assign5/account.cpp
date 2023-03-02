//********************************************************************
//
// account.cpp
// CSCI 241 Assignment 5
//
// Created by Leang Y Chheav (z-id: Z1966108)
// and Sam Normoyle (z-id: Z1980761)
//********************************************************************
#include <iostream>
#include "account.h"

using std::cout;
using std::cin;
using std::endl;

/***
 * The default constructor should set the account number 
 * and customer name data members to the string literal "None".
 * The account balance data member should be set to 0.
*/
account::account(){
    char account_number[11] = {"None"};
    char custom_name[21] = {"None"};
    double current_account_balance = 0.00;
}

/***
 * This member function has no parameters
 * @return account number
*/
int account::get_account_number(){
    return account_number;
}

/***
 * This member function has no parameters
 * @return current account
*/
double account::get_balance(){
    return current_account_balance;
}

/***
 * This member function take a double deposit amount 
 * and add it to the balance for the bank account.
 * @return nothing
*/
void account::process_deposit(double deposit_amount){
    current_account_balance += deposit_amount;
}

/***
 * This member function should a double withdrawal amount.
 * If the bank account's balance is less than the withdrawal amount,
 * the member function should just return false.
 * Otherwise, subtract the withdrawal amount from the balance of the bank account return true.
 * @return boolean.
*/
bool account::process_withdrawal(double withdrawal_amount){
    if(current_account_balance < withdrawal_amount){
        return false;
    }else{
        current_account_balance -= withdrawal_amount;
        return true;
    }
}

/***
 * This member function has no parameters.
 * It should print the values of the data members for the account in a format similar to the following:
 * @return nothing
*/
void account::print(){
    cout << "Account Number: ";
    for(int i = 0; i < 11; i++){
        account_number[i];
    }
    cout << endl;

    cout << "Name: ";
    for(int i = 0; i < 21; i++){
        custom_name[i];
    }
    cout << endl;

    cout << "Balance: $" << current_account_balance << endl;
}

