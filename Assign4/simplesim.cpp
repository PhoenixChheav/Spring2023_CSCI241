//********************************************************************
//
// simplesim.cpp
// CSCI 241 Assignment 4
//
// Created by Leang Y Chheav (z-id: Z1966108)
// and Sam Normoyle (z-id: Z1980761)
//********************************************************************


#include <iostream>
#include <iomanip>
#include "simplesim.h"
#include "sml.h"

using std::cin;
using std::cout;
using std::endl;
using std::internal;
using std::left;
using std::noshowpos;
using std::right;
using std::setfill;
using std::setw;
using std::showpos;

/**
 * Initializes the Simplesim's memory to default values.
 */
simplesim::simplesim()
{
    accumulator = 0;
    instruction_counter = 0;
    instruction_register = 0;
    operation_code = 0;
    operand = 0;
    
    
    for(int i = 0; i < 100; i++){
        memory[i] = 7777;
    }
}

/**
 * Loads an SML program into the Simplesim's memory.
 *
 * @return Returns true if a valid program is successfully loaded into 
 *         memory; otherwise, false.
 */
bool simplesim::load_program()
{
    int count = 0;          // Instruction count.
    int instruction = 0;    // Holds instruction read.

    // While not EOF and we have not encountered the sentinel value...
    while (cin >> instruction && instruction != -99999)
    {
        // Check for an invalid word. If invalid, print error message
        // and return false.

        if(instruction > -9999 && instruction < 9999){
            // Check for too large a program. If count is outside the 
            // boundaries of the memory array, print error message and
            // return false.
            if(count >= 100){
                cout << "*** ABEND: pgm load: pgm too large ***" << endl << endl;
                return false;
            }

            if(count < 100){
                memory[count] = instruction;
                count++;
            }

            //cout << instruction << endl;
        }else{
            cout << "*** ABEND: pgm load invalid word ***" << endl << endl;
            return false;
        }
        
	}

    return true;
}

/**
 * Executes an SML program loaded into the Simplesim's memory.
 */
void simplesim::execute_program()
{
    bool done = false;

    while (!done)
    {
        // Check for an addressability error. If instruction_counter
        // is outside the boundaries of the memory array, print error
        // and return.
        if(instruction_counter > 100){
            cout << "*** ABEND: program is too large ***" << endl;
            return;
        }else if(instruction_counter >= 0 && instruction_counter < 100){
            // Fetch the instruction and extract the operation code
            // and operand.
            instruction_register = memory[instruction_counter];
            operation_code = instruction_register / 100;
            operand = instruction_register % 100;

            // cout << "Operand code: " << operation_code << endl;
            // cout << "Operand: " << operand << endl;
            
            //new var
            int value=0;
            int temp = 0;

            // Execute the correct instruction.
            switch (operation_code)
            {
            case READ:
                cin >> value;
                if( value >= -9999 && value <= 9999){
                    memory[operand] = value;
                    cout << "READ: "<< showpos << setw(5) << setfill('0')  << internal << value << noshowpos << setfill(' ') <<endl;
                }else{
                    cout << "*** ABEND: illegal input ***" << endl;
                    return; 
                }
                // return;
                break;

            case WRITE:
                cout << showpos << setw(5) << setfill('0')  << internal << memory[operand] << noshowpos << setfill(' ') <<endl;
                break;

            //- Insert cases for the other op codes.
            case LOAD:
                accumulator = memory[operand];
                break;

            case STORE:
                memory[operand] = accumulator;
                break;

            case ADD: 
                temp = accumulator + memory[operand];
                if(temp < -9999){
                    cout<< "*** ABEND: underflow ***" << endl;
                    return;
                }
                if(temp > 9999){
                    cout<< "*** ABEND: overflow ***" << endl;
                    return;
                }
                accumulator = temp;
                break; 
            
            case SUBTRACT:
                temp = accumulator - memory[operand];
                if(temp < -9999){
                    cout<< "*** ABEND: underflow ***" << endl;
                    return;
                }
                if(temp > 9999){
                    cout<< "*** ABEND: overflow ***" << endl;
                    return;
                }
                accumulator = temp;
                break; 
            
            case MULTIPLY:
                temp = accumulator * memory[operand];
                if(temp < -9999){
                    cout<< "*** ABEND: underflow ***" << endl;
                    return;
                }
                if(temp > 9999){
                    cout<< "*** ABEND: overflow ***" << endl;
                    return;
                }
                accumulator = temp;
                break; 

            case DIVISION:
                if(memory[operand] == 0){
                    cout<<"*** ABEND: attempted division by 0 ***"<<endl;
                    return;
                }
                temp = accumulator / memory[operand];
                if(temp < -9999){
                    cout<< "*** ABEND: underflow ***" << endl;
                    return;
                }
                if(temp > 9999){
                    cout<< "*** ABEND: overflow ***" << endl;
                    return;
                }
                accumulator = temp;
                break;

            case BRANCHNEG:
                if(accumulator < 0){
                    instruction_counter = operand;
                }
                else{
                    instruction_counter++;
                }
                break;

            case BRANCHZERO:
                if(accumulator == 0){
                    instruction_counter = operand;
                }
                break;

            case HALT:
                done = true;
                cout << "*** Simplesim execution terminated ***" << endl;
                return;
                break;

            default:
                cout << "*** ABEND: invalid opcode ***\n";
                return;
            }

            // If not done and current operation code is not one
            // of the BRANCH op codes, increment instruction_counter.

            if((operation_code != 41 && operation_code != 42 && operation_code != 43) && done == false){
                instruction_counter++;
            }
            
            

            // if(operation_code == 44){
            //     return;
            // }
        }else{
            cout << "*** ABEND: addressability error ***" << endl;
            return;
        }
    }

    // Print successful termination message.
	cout << "*** ABEND: Simplesim execution terminated ***\n";
}

/**
 * Prints the contents of the Simplesim's registers and memory.
 */
void simplesim::dump() const
{
    // Print registers.
    
    cout << endl;
    cout << "REGISTERS:" << endl;
    cout << setw(24) << left << "accumulator:" << showpos << setfill('0') << setw(5) << internal << accumulator << noshowpos << setfill(' ') << endl;
    
    cout << setw(24) << left << "instruction_counter:" << setfill('0') << setw(2) << right << instruction_counter << setfill(' ') << endl;
    
    cout << setw(24) << left << "instruction_register:" << showpos << setfill('0') << setw(5) << instruction_register <<  noshowpos << setfill(' ') << endl;
    
    cout << setw(24) << left << "operation_code:" << setfill('0') << setw(2) << right << operation_code << setfill(' ') << endl;
    cout << setw(24) << left << "operand:" << setfill('0') << setw(2) << right << operand << setfill(' ') << endl;

    cout << endl;
    
    cout << "MEMORY:" << endl;

    // Print memory.

    for(int i = 0; i < 10; i++){
        if(i == 0){
            cout << setw(8) << right << i;
        }else{
            cout << setw(6) << right << i;
        }
        
    }
    cout << endl;

    for(int i = 0; i < 100; i ++){

        int j = 0;
    
        

        if(i != 0 && i % 10 == 0){
            cout << endl;
            cout << noshowpos << setw(2) << right << i;
        }
        
        if(i == 0){
            cout << setw(2) << right << j ;
        }
        
        cout << " " << setw(3) << showpos << setw(5) << setfill('0')  << internal << memory[i]<< noshowpos << setfill(' ');


        // if(i == 0){
        //     cout << "  ";
        // }else{
        //     cout << i ;
        // }

        // for(int j = 0; j < 10; i++){
        //     cout << 
        // }
    }
    cout << endl;

}
