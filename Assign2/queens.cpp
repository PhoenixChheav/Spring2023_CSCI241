//*******************************************************************
//
//  queens.cpp
//  CSCI 241 Assignment 2
//
//  Created by your-name (your-z-id)
//
//*******************************************************************

#include <iostream>
#include <iomanip>

using namespace std;

   // Number of rows, columns, and queens to place.

// Class to represent a solution to the N Queens puzzle.

class queen_solver
{
private:

    bool board[8][8] = {{false}};

public:

    queen_solver() = default;
    bool place_queens();
    bool place_queen_in_row(int);
    bool is_safe(int, int) const;
    void print_solution() const;
};


int main()
{
    // Create an instance of the queen_solver class.
    queen_solver q;

    // Try to place the N queens. If successful, print the
    // solution. If not, print an error message.
    //
    // Note: This should not fail for N = 8 if the program works.
    
    if (q.place_queens())
        q.print_solution();
    else
        cout << "Error - no solution found\n";

    return 0;
}

/**
 * Attempts to place the N queens, starting with row 0.
 *
 * @return Returns true if successful; otherwise, false.
 */
bool queen_solver::place_queens()
{
    return place_queen_in_row(0);
}

/**
 * Attempts to place a single queen in a specified row.
 *
 * @param row The row in which to attempt to place a queen.
 *
 * @return Returns true if successful; otherwise, false.
 */
bool queen_solver::place_queen_in_row(int row)
{
    // Base case #1 - All queens have been placed successfully.
    if (row >= 8)
        return true;

    // Loop through the columns of this row and try to place a queen.
    for (int col = 0; col < 8; col++)
    {
        // If this board square is safe, place the queen here.
        if (is_safe(row, col))
        {
            board[row][col] = true;

            // Try to place a queen in all the rows below this one.
            if (place_queen_in_row(row + 1)){
                // Base case #2 - All queens in rows below this one
                // have been successfully placed.
                return true;
            
            // If we did not return true, that means we were not able to
            // place the remaining queens in the rows below this one.
            // Remove the queen we placed and try the next column.
            
            
            }
            else{
                board[row][col] = false;
            }
        }
    }
    
    // Base case #3 - We were not able to safely place a queen anywhere in 
    // this row.
    return false;
}

/**
 * Checks whether a board square is safe from attack by other queens.
 *
 * @param row The row of the board square to be checked.
 * @param col The column of the board square to be checked.
 *
 * @return Returns true if the square is safe; otherwise, false.
 */
bool queen_solver::is_safe(int row, int col) const
{
    // Check the rows above this column. col stays the same, row varies
    // from row - 1 down to 0.
    
    for (int i = row -1; i>= 0; i--){
        if (board[i][col]) {
            return false;
        }
    }

    // Check the left diagonal above this row. col varies from col - 1
    // down to 0, row varies from row - 1 down to 0.
    
    int i = row -1;
    int j = col -1;
    while(j >= 0 && i>=0){
        if(board[i][j]){
            return false;
        }
        i--;
        j--;
    }

    // Check the right diagonal above this row. col varies from col + 1
    // up to 7, row varies from row - 1 down to 0.
    
    i = row -1;
    j = col + 1;
    while(i >= 0 && j < 8){
        if(board[i][j]){
            return false;
    
        }
        i--;
        j++;
    }

    return true;
}

/**
 * Prints the board containing the solution.
 */
void queen_solver::print_solution() const
{
for (int i  = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j]) {
                cout << setw(3) << "1";
            } else {
                cout << setw(3) << "0";
            }
        }
        cout << endl; 
    }
}