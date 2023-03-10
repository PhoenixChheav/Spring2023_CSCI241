#ifndef SOLUTION_H
#define SOLUTION_H

class solution
{
private:
   
    int grid[9][9];
   
public:
   
    solution();
    void read();
    bool verify() const;
    void print() const; 
};

#endif