//***************************************************************************
//
//  hanoi.cpp
//  CSCI 241 Assignment 2
//
//  Sam Normoyle (Z-ID: Z1980761)
//  Leang Y Chheav(Z-ID: Z1966108)
//***************************************************************************

#include <string>
#include <cctype>
#include <cstdlib>
#include <iostream>

using namespace std;

void hanoi(int , int , int, int);

int main(int argc, char* argv[])
{

        // Make sure that argument string contains nothing but digits
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            cout << "Bad character in command line argument\n";
            exit(1);
        }
    }

    int disks = stoi(argv[1]);
    hanoi(disks, 1, 2, 3);

    return 0;

}

void hanoi(int n, int source_rod, int destination_rod, int temp_rod){
    //check if n == 1, there is only 1 disk, so we move it directly to the destination rod
    if(n == 1){
        cout<< "1 " << source_rod << "->" << destination_rod << endl;
        return;
    }

    /**
     * move the top rod which is N to the destintion rod
     * then the N-1 will be the top one, so we move it to the temp rod
     * we then move the N rod to the temp rod
     * then move the next one to the destination rod
     * check if N==1, if it is true move the N from temp rod to source rod
     * and move the N-1 disk to destination rod 
     * finally move the N disk from the source rod to the destination rod
     * 
    */
    hanoi(n - 1, source_rod, temp_rod, destination_rod);
    cout << n << " " << source_rod << "->" << destination_rod << endl;
    hanoi(n - 1, temp_rod, destination_rod, source_rod);
}