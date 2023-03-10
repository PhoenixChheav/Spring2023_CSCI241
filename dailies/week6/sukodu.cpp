#include <iostream>
#include "solution.h"

using std::cout;

int main()
{
    solution s;
   
    // Read the solution file as input
    s.read();
   
    // Print the Sudoku grid
    s.print();
  
    // Verify whether or not the solution is correct
    if (s.verify())
        cout << "VALID SOLUTION\n";
    else
        cout << "INVALID SOLUTION\n";

    return 0;
}