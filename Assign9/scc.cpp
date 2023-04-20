//**************************************
//
// scc.cpp
// CSCI 241 Assignment 9
//
//  Created by Leang Y Chheav (z1966108) and Sam Normoyle (z-id: Z1980761)
//
//**************************************

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>

#include "sml.h"
#include "inpost.h"

using namespace std;

/**
 *
 * Symbol table entry.
 *
 */

struct table_entry
{
    int symbol;
    char type;
    int location;
};

/**
 *
 * Simple compiler.
 *
 */
class scc
{
public:

    // Data members
    static const int MEMORY_SIZE = 100;
    static const int SYMBOL_TABLE_SIZE = 1000;

    // Member functions
    scc(); // constructor
    void first_pass();
    void second_pass();
    void print_program() const;

private:

    // Data members
    int memory[MEMORY_SIZE];    // Program memory.
    int data[MEMORY_SIZE];      // Input data values.
    int ndata = 0;              // Number of input data values.

    table_entry symbol_table[SYMBOL_TABLE_SIZE];     // Symbol table.
    
    int flags[MEMORY_SIZE];     // Array of flags to mark partial
                                // isntructions.

    int next_instruction_addr = 0;    // Address of next instruction.
    int next_const_or_var_addr = MEMORY_SIZE - 1;
    int next_symbol_table_idx = 0;

    // Member functions

    void memory_check() const;
    void data_check() const;
    void stack_space_check(int) const;

    int get_symbol_location(const string&);
    int search_symbol_table(int, char) const;

    void handle_input(istringstream&);
    void handle_data(istringstream&);
    void handle_end();
    // etc...
    void handle_print(istringstream&);
    void handle_goto(istringstream&);
    void handle_if(istringstream&);
    void handle_let(istringstream&, const string&);
    void display_table();
    void display_memory_array();
};

/**
 * Compiles a Simple program to SML and
 * prints it to standard output.
 */
int main()
{
    scc compiler;

    compiler.first_pass();

    compiler.second_pass();

    compiler.print_program();

    return 0;
}

/**
 * Constructor - initializes memory and flags arrays.
 */
scc::scc()
{
    for (int i = 0; i < MEMORY_SIZE; i++)
    {
        memory[i] = DEFAULT;
        flags[i] = -1;
    }
}

/**
 * Performs first pass of compilation.
 */
void scc::first_pass()
{
    string buffer1, buffer2, command;
    int line_number;

    // While there are more program statements...
    while (getline(cin, buffer1))
    {
        buffer2 = buffer1;         // buffer2 used for 'let'
        istringstream ss(buffer1);

        // Read the line number of the program statement.
        ss >> line_number;

        // Add the line number to the symbol table with type 'L'.
        symbol_table[next_symbol_table_idx].symbol = line_number;
        symbol_table[next_symbol_table_idx].type = 'L';
        symbol_table[next_symbol_table_idx]. location = next_instruction_addr;
        next_symbol_table_idx++;

        // Read the command of the program statement.
        ss >> command;

        // Determine what kind of command this is and take
        // action accordingly.
        if (command == "input")
        {
            // ... code to process 'input' command ...
            //cout << "input command" << endl;
            handle_input(ss);
            //DONE
        }
        else if (command == "data")
        {
            // ... code to process 'data' command ...
            //cout << "data command" << endl;
            handle_data(ss);
            //DONE
        }
        else if (command == "let")
        {
            // ... code to process 'let' command ...
            //cout << "let command" << endl;
            handle_let(ss, buffer2);
        }
        else if (command == "goto")
        {
            // ... code to process 'goto' command ...
            //cout << "goto command" << endl;
            handle_goto(ss);
            //DONE   
        }
        else if (command == "if")
        {
            // ... code to process 'if' command ...
            //cout << "if command" << endl;
            handle_if(ss);
        }
        else if (command == "print")
        {
            // ... code to process 'print' command ...
            //cout << "print command" << endl;
           // handle_print(ss);
            //DONE
        }
        else if (command == "rem")
        {
            // ... code to process 'rem' command ...
            //cout << "rem command" << endl;
            //memory_check();
            // Nothing to do here.
        }
        else
        {
            // ... code to process 'end' command ...
            handle_end();
            //DONE
        }
    }
    //display_table();//OPTIONAL Display Table
    //display_memory_array(); //OPTIONAL Display Memory
}

/**
 * Performs second pass of compilation.
 */
void scc::second_pass()
{
    int index;

    // Compute the starting location of the stack, just
    // above the constants and variables.
    int stack_start = next_const_or_var_addr - 1;

    // Loop through the flags and memory arrays.
    for (int i = 0; i < next_instruction_addr; i++)
    {
        // If the instruction is marked incomplete in the flags array...
        if (flags[i] != -1)
        {
            if (flags[i] > 0)
            {
                // Line number for goto instruction.
                index = search_symbol_table(flags[i], 'L');
                memory[i] += symbol_table[index].location;
            }
            // else if(flags[i] == 0){
            //     memory[i] += next_const_or_var_addr;
            // }
            else if (flags[i] == -2)
            {
                 memory[i] += next_const_or_var_addr;
                // Special right operand location.
            }
            else if (flags[i] < -2)
            {
                index = -3 - flags[i];

                int location = stack_start - index;
                stack_space_check(location);
                // Stack location.

                // add value of location to memory
                memory[i] += location;
            }
        }
    }

}

/**
 * Prints memory and data for the compiled SML program.
 */
void scc::print_program() const
{
    cout << setfill('0') << internal << showpos;

    // Print the entire memory array.
    for (int i = 0; i < MEMORY_SIZE; i++)
        cout << setw(5) << memory[i] << endl;

    // Print the "end of instructions" sentinel value.
    cout << -99999 << endl << noshowpos;

    // Print the input data values.
    for (int i = 0; i < ndata; i++)
        cout << data[i] << endl;
}

/**
 * Checks whether there is room in the memory array to add
 * another instruction.
 */
void scc::memory_check() const
{
    if (next_instruction_addr >= MEMORY_SIZE || next_instruction_addr > next_const_or_var_addr)
    {
        cout << "*** ERROR: ran out of Simplesim memory ***\n";
        exit(1);
    }
}

/**
 * Checks whether there is room in the data array to add
 * another data item.
 */
void scc::data_check() const
{
    if (ndata >= MEMORY_SIZE)
    {
        cout << "*** ERROR: too many data lines ***\n";
        exit(1);
    }
}

/**
 * Checks whether the top of the stack has crossed into
 * the region of the memory array that contains instructions.
 *
 * @param location Location of the top of the stack.
 */
void scc::stack_space_check(int location) const
{
    // If top of the stack has hit the instructions...
    if (location < next_instruction_addr)
    {
        cout << "*** ERROR: insufficient stack space ***\n";
        exit(1);
    }
}

/**
 * Gets the location of a constant or variable, adding it
 * to the symbol table and memory if necessary.
 *
 * @param token The symbol to locate.
 *
 * @return The symbol's location.
 */
int scc::get_symbol_location(const string& token)
{
    int location, symbol;
    char type;

    // Examine first character of the token string.
    
    if (islower(token[0]))
    {
        // This is a variable.
        symbol = token[0];
        type = 'V';
    }
    else
    {
        // try {
        //     symbol = stoi(token);
        //     // use symbol
        // } catch (const std::invalid_argument& e) {
        //     cerr << "Error: could not convert '" << token << "' to integer.\n";
        // }   
        // This is an integer constant.
        symbol = stoi(token);
        type = 'C';
    }

    // Search for this symbol in the symbol table.
    int index = search_symbol_table(symbol, type);

    if (index == -1)
    {
        // This symbol is not in the symbol table yet.
        
        // Add this symbol to the symbol table and memory.
        location = next_const_or_var_addr;

        // Add symbol to symbol table.
        symbol_table[next_symbol_table_idx].symbol = symbol;
        symbol_table[next_symbol_table_idx].type = type;
        symbol_table[next_symbol_table_idx].location = location;
        next_symbol_table_idx++;

        // Add this constant or variable to memory.
        memory_check();
        if (type == 'V')
            memory[location] = 0;
        else
            memory[location] = symbol;

        next_const_or_var_addr--;
    }
    else
    {
        // This symbol is in the symbol table at element
        // index, so get its location in memory.
        location = symbol_table[index].location;
    }

    // Return the location in memory of the symbol.
    
    return location;
}

/**
 * Searches the symbol table for a symbol with a particular
 * type.
 *
 * @param symbol The symbol to search for.
 * @param type The type of the symbol to search for.
 *
 * @return The location of the symbol or -1 if the search
 *         failed.
 *
 * @note Uses the linear search algorithm.
 */
int scc::search_symbol_table(int symbol, char type) const
{
    for (int i = 0; i < next_symbol_table_idx; i++)
    {
        // If we find a match for the symbol, return the
        // table index.
        if (symbol == symbol_table[i].symbol && type == symbol_table[i].type)
            return i;
    }

    // Search failed; return a failure signal.
    return -1;
}

/**
 * Generates code for a "input" instruction.
 *
 * @param ss Input string stream from which to read.
 */
void scc::handle_input(istringstream& ss)
{
    string token;

    // Read the variable name for this input command.
    
    ss >> token;

    // Get the memory location of that variable.
    
    int location = get_symbol_location(token);

    // Generate a READ instruction for that location.
    
    memory_check();
    memory[next_instruction_addr] = READ * 100 + location;
    next_instruction_addr++;
}

/**
 * Generates code for a "data" instruction.
 *
 * @param ss Input string stream from which to read.
 */
void scc::handle_data(istringstream& ss)
{
    int number;

    // Read the data value for this data command.
    
    ss >> number;
    
    // Add the value to the data array.
    
    data_check();
    data[ndata] = number;
    ndata++;
}

/**
 * Generates code for an "end" instruction.
 */
void scc::handle_end()
{
    // Generate a HALT instruction.
    
    memory_check();
    memory[next_instruction_addr] = HALT * 100;
    next_instruction_addr++;
}

/***
 * 
 * Generates code for "print" instruction 
 * 
***/
void scc::handle_print(istringstream& ss)
{
    string token;

    // Read the variable name for this input command.
    
    ss >> token;

    // Get the memory location of that variable.
    
    int location = get_symbol_location(token);

    // Generate a READ instruction for that location.
    
    memory_check();
    memory[next_instruction_addr] = WRITE * 100 + location;
    next_instruction_addr++;
}

/***
 * 
 * Generates code for a "goto" instruction
 * 
***/
void scc::handle_goto(istringstream& ss){
    string token;

    ss >> token; //read token through ss

    //perform a search for the line number appearing at the end of the line
    int index = search_symbol_table(stoi(token), 'L');

    memory_check();
    //if line number appears in the symbol table
    if(index == -1){
        memory[next_instruction_addr] = 100 * BRANCH;
        flags[next_instruction_addr] = stoi(token);
    }else{//if it's not in the symbol table
        memory[next_instruction_addr] = (100 * BRANCH) + symbol_table[index].location;
    }
    next_instruction_addr++;
}

/***
 * 
 * Generates code for an "if" instruction
 * 
***/
void scc::handle_if(istringstream& ss){
    string relop, lop, rop, ignored;
    int lop_location, rop_location, linenum;

    //read left operator into ss
    ss >> lop;
    //read relational operator into ss
    ss >> relop;

    //read right operator into ss
    ss >> rop;

    //find the location of the lop
    lop_location = get_symbol_location(lop);

    //search symbol table
    ss >> ignored;
    
    //find the location of the rop
    rop_location = get_symbol_location(rop);
    ss >> linenum;

    
    
    //read line number into ss
    int index = search_symbol_table(linenum, 'L');


    //check for which relop is used
    if(relop == "=="){

        //LOAD
        memory_check(); // check if there's room in the memory array
        memory[next_instruction_addr] = 100 * LOAD + lop_location;
        next_instruction_addr++;

        //SUBTRACT
        memory_check();
        memory[next_instruction_addr] = 100 * SUBTRACT + rop_location;
        next_instruction_addr++;

        //BRANCHNEG
        memory_check();
        if(index == -1){
            memory[next_instruction_addr] = 100 * BRANCHZERO;
            flags[next_instruction_addr] = linenum;
        }else{
            memory[next_instruction_addr] = 100 * BRANCHZERO + symbol_table[index].location;
        }
        next_instruction_addr++;
    }else if(relop == "!="){
        //LOAD
         memory_check();
        memory[next_instruction_addr] = 100 * LOAD + lop_location;
        next_instruction_addr++;
        
        //SUBTRACT
        memory_check();
        memory[next_instruction_addr] = 100 * SUBTRACT + rop_location;
        next_instruction_addr++;
        
        //BRANCHZERO
        memory_check();
        memory[next_instruction_addr] = 100 * BRANCHZERO + next_instruction_addr + 2;
        next_instruction_addr++;

        //BRANCH
        memory_check();
        if(index == -1){
            memory[next_instruction_addr] = 100 * BRANCH;
            flags[next_instruction_addr] = linenum;
        }else{
            memory[next_instruction_addr] = 100 * BRANCH + symbol_table[index].location;
        }
        next_instruction_addr++;
    }else if(relop == "<"){
        //LOAD
        memory_check(); // check if there's room in the memory array
        memory[next_instruction_addr] = 100 * LOAD + lop_location;
        next_instruction_addr++;

        //SUBTRACT
        memory_check();
        memory[next_instruction_addr] = 100 * SUBTRACT + rop_location;
        next_instruction_addr++;

        //BRANCHNEG
        memory_check();
        if(index == -1){
            memory[next_instruction_addr] = 100 * BRANCHNEG;
            flags[next_instruction_addr] = linenum;
        }else{
            memory[next_instruction_addr] = 100 * BRANCHNEG + symbol_table[index].location;
        }
        next_instruction_addr++;
    }else if(relop == "<="){

        //LOAD
        memory_check(); // check if there's room in the memory array
        memory[next_instruction_addr] = 100 * LOAD + lop_location;
        next_instruction_addr++;

        //SUBTRACT
        memory_check();
        memory[next_instruction_addr] = 100 * SUBTRACT + rop_location;
        next_instruction_addr++;

        //BRANCHNEG
        memory_check();
        if(index == -1){
            memory[next_instruction_addr] = 100 * BRANCHNEG;
            flags[next_instruction_addr] = linenum;
            next_instruction_addr++;

            memory_check();
            memory[next_instruction_addr] = 100 * BRANCHZERO;
            flags[next_instruction_addr] = linenum;
        }else{
            memory[next_instruction_addr] = 100 * BRANCHNEG + symbol_table[index].location;
            next_instruction_addr++;

            memory_check();
            memory[next_instruction_addr] = 100 * BRANCHZERO + symbol_table[index].location;
        }
        next_instruction_addr++;
    }else if(relop == ">"){
        //LOAD
        memory_check(); // check if there's room in the memory array
        memory[next_instruction_addr] = 100 * LOAD + rop_location;
        next_instruction_addr++;

        //SUBTRACT
        memory_check();
        memory[next_instruction_addr] = 100 * SUBTRACT + lop_location;
        next_instruction_addr++;

        //BRANCHNEG
        memory_check();
        if(index == -1){
            memory[next_instruction_addr] = 100 * BRANCHNEG;
            flags[next_instruction_addr] = linenum;
        }else{
            memory[next_instruction_addr] = 100 * BRANCHNEG + symbol_table[index].location;
        }
        next_instruction_addr++;
    }else if(relop == ">="){
        //LOAD
        memory_check(); // check if there's room in the memory array
        memory[next_instruction_addr] = 100 * LOAD + rop_location;
        next_instruction_addr++;

        //SUBTRACT
        memory_check();
        memory[next_instruction_addr] = 100 * SUBTRACT + lop_location;
        next_instruction_addr++;

        //BRANCHNEG
        memory_check();
        if(index == -1){
            memory[next_instruction_addr] = 100 * BRANCHNEG;
            flags[next_instruction_addr] = linenum;
            next_instruction_addr++;

            memory_check();
            memory[next_instruction_addr] = 100 * BRANCHZERO;
            flags[next_instruction_addr] = linenum;
        }else{
            memory[next_instruction_addr] = 100 * BRANCHNEG + symbol_table[index].location;
            next_instruction_addr++;

            memory_check();
            memory[next_instruction_addr] = 100 * BRANCHZERO + symbol_table[index].location;
        }
        next_instruction_addr++;
    }
}

/***
 * 
 * Generates code for a "let" instruction
 * 
***/
void scc::handle_let(istringstream& ss, const string& buffer2){
    
    string left_variable;

    ss >> left_variable; //extract next value from string stream

    int left_variable_location = get_symbol_location(left_variable);

    // buffer2 = buffer1;
    size_t sub = buffer2.find_first_of("=");
    string infix = buffer2.substr(sub + 2, string::npos);
    string postfix = convert(infix);

    string op;//operand
    istringstream ss2(postfix); //create a stringstream objct

    // int sub_post = 0;
    int op_location;
    int next_stack_idx = 0;
    while(ss2 >> op ){
        if(isdigit(op[0]) || islower(op[0])){
            op_location = get_symbol_location(op); //find operand location
            
            //LOAD
            memory_check(); // check memory
            memory[next_instruction_addr] = 100 * LOAD + op_location;
            next_instruction_addr++;

            //STORE
            memory_check();
            memory[next_instruction_addr] = 100 * STORE;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;
            next_stack_idx++;

        }else
        
        if(op == "+" || op == "*"){//if op is '+' or '*'
            
            //LOAD
            memory_check();
            memory[next_instruction_addr] = LOAD * 100;
            next_stack_idx--;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;

            //ADD
            memory_check();
            if(op == "+"){//ADD
                memory[next_instruction_addr] = ADD * 100;
            }else
            if(op == "*"){//MULTIPLY
                memory[next_instruction_addr] = MULTIPLY * 100;
            }
            next_stack_idx--;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;

            memory_check();
            memory[next_instruction_addr] = STORE * 100;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;
            next_stack_idx++;

        }else

        if(op == "-" || op == "/"){//if op is '-' or '/'
            
            //LOAD
            memory_check();
            memory[next_instruction_addr] = 100 * LOAD;
            next_stack_idx--;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;

            //STORE
            memory_check();
            memory[next_instruction_addr] = STORE * 100;
            flags[next_instruction_addr] = -2;
            next_instruction_addr++;

            //LOAD
            memory_check();
            memory[next_instruction_addr] = LOAD * 100;
            next_stack_idx--;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;

            memory_check();

            if(op == "-"){ //if op is "-"
                memory[next_instruction_addr] = SUBTRACT * 100;
            }else
            if(op == "/"){ // if op is "/"
                memory[next_instruction_addr] = DIVIDE * 100;
            }
            flags[next_instruction_addr] = -2;
            next_instruction_addr++;

            memory_check();
            //STORE
            memory[next_instruction_addr] = STORE * 100;
            flags[next_instruction_addr] = -3 - next_stack_idx;
            next_instruction_addr++;
            next_stack_idx++;
            //postfix has been evaluated
        }
    }
        memory_check();
        //LOAD
        memory[next_instruction_addr] = LOAD * 100;
        flags[next_instruction_addr] = -3;
        next_instruction_addr++;

        memory_check();
        //STORE
        memory[next_instruction_addr] = STORE * 100 + left_variable_location;
        next_instruction_addr++;

}


/***
 * 
 * Generates table
 * 
***/
void scc::display_table() 
{
    for (int i = 0; i < next_symbol_table_idx; i++)
    {
        if (symbol_table[i].type == 'V')
        {
            char type_cast(symbol_table[i].symbol);
            cout << type_cast << " " << symbol_table[i].type << " " << symbol_table[i].location << " " << endl;
        }
        else
        {
            cout << symbol_table[i].symbol << " " << symbol_table[i].type << " " << symbol_table[i].location << " " << endl;
        }
    }
}

void scc::display_memory_array(){
    for (int i = 0; i < MEMORY_SIZE; i++){
        //cout << "display memory array" << endl;
        cout << memory[i] << endl;
    }
}