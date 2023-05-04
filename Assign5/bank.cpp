#include <iostream>
#include <fstream>
#include <cstring>
#include "bank.h"
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using ifstream::read();
using std::utility;
using std::setw();
using std::right;
using std::fixed;
using std::setprecision();

bank::bank(){
    char bank_name[31] = {"None"};
    bank account[20] = {"None"};
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
    myfile.read((char*) &bank_name[number], sizeof(object));
    myfile.close();

    /***
     * Sort the account objects in the array in ascending order by account number using a sorting algorithm of your choice.
     ***Note that the account numbers are C strings, which means that you will not be able to compare them using the standard relational operators.
     ***The account number is also private data of the account class,
     * so code in the bank will need to call get_account_number() for an account object rather than accessing the object's account number directly.
    */
   sort_array();
   
}
void bank::process_transactions(string file_transactation){
    ifstream myfile;
    myfile.open(file_transactation);

    if(!myfile){
        cerr << "Error - unable to open input file" << file_transactation << endl;
        exit(1);
    }

    cout << "Transactation Report " << endl << endl;
    cout << "Date" << setw(4) << right << "Account" << setw(6) << right << "Type" << setw(3) << right << "Amount" << setw(5) << left << "New Balance" << endl;
    cout << endl;
    
    string date;
    int index;

    while(myfile >> date){
        
    }

}
void bank::print(){

}

/**
 * Sorts a list of integers in ascending order.
 *
 * @param array The list of integers to sort.
 * @param n The size of the list.
 *
 * @note Uses the selection sort algorithm.
 */
void bank::sort_array()
{
    int i, j, min_index;
    // int temp;

    for (i = 0; i < number - 1; i++)
    {
        // Locate the smallest value in the unsorted part of the list.

        min_index = i;
        for (j = i + 1; j < number; j++)
            if (strcmp(account[min_index].get_account_number(), account[j].get_account_number) > 0)
                min_index = j;

        // Swap smallest value with first unsorted value.
        swap(&account[i], &account[min_index]);

        /*
        temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
        */
    }
}

int bank::binary_search(int account_num[]){
    int mid;
    int low = 0;
    int high = number -1;
    while(low <= high){
        mid = (low + high)/2;
        if(strcmp(account_num, account[mid].get_account_number) == 0){
            return mid;
        }
        
        if(strcmp(account_num, account[mid].get_account_number) < 0){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}