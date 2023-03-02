#include <iostream>
#include <fstream>
#include <cstring>
#include "bank.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using ifstream::read();

bank::bank(){
    char bank_name[31] = {"None"};
    bank object[20] = {"None"};
    int number = 0;
}

void bank::read_accounts(string bank_file){
    ifstream myfile;
    myfile.open(bankfile); //convert string to const char
    
    if(!myfile){
        cerr << "Error - unable to open input file" << bank_file << endl;
        exit(1);
    }
    
    //read
    myfile.read((char*) &list[number], sizeof(object));
    myfile.close();

    /***
     * Sort the account objects in the array in ascending order by account number using a sorting algorithm of your choice.
     ***Note that the account numbers are C strings, which means that you will not be able to compare them using the standard relational operators.
     ***The account number is also private data of the account class,
     * so code in the bank will need to call get_account_number() for an account object rather than accessing the object's account number directly.
    */
}
void bank::process_transactions(string file_transactation){

}
void bank::print(){

}

