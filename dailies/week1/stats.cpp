#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

int minimum(int array[], int n);
int maximum(int array[], int n);
int range(int array[], int n);
double average(int array[], int n);
double median(int array[], int n);
double stddev(int array[], int n);

int main()
{
    int a1[10] = {66, 68, 70, 72, 75, 84, 86, 86, 89, 92};
    int a2[9] = {59, 66, 68, 70, 72, 75, 86, 89, 92};
    int a3[20] = {47, 49, 51, 52, 60, 65, 67, 68, 71, 72, 77, 78, 79, 80, 83, 84, 85, 86, 89, 100};
    int n;
    
    cout << fixed << setprecision(2);
    
    n = 10;
    
    cout << "Count:              " << n << '\n';
    cout << "Minimum Value:      " << minimum(a1, n) << '\n';
    cout << "Maximum Value:      " << maximum(a1, n) << '\n';
    cout << "Range:              " << range(a1, n) << '\n';
    cout << "Average:            " << average(a1, n) << '\n';
    cout << "Median:             " << median(a1, n) << '\n';
    cout << "Standard Deviation: " << stddev(a1, n) << '\n';
    cout << endl;
    
    n = 9;

    cout << "Count:              " << n << '\n';
    cout << "Minimum Value:      " << minimum(a2, n) << '\n';
    cout << "Maximum Value:      " << maximum(a2, n) << '\n';
    cout << "Range:              " << range(a2, n) << '\n';
    cout << "Average:            " << average(a2, n) << '\n';
    cout << "Median:             " << median(a2, n) << '\n';
    cout << "Standard Deviation: " << stddev(a2, n) << '\n';
    cout << endl;

    n = 20;
    
    cout << "Count:              " << n << '\n';
    cout << "Minimum Value:      " << minimum(a3, n) << '\n';
    cout << "Maximum Value:      " << maximum(a3, n) << '\n';
    cout << "Range:              " << range(a3, n) << '\n';
    cout << "Average:            " << average(a3, n) << '\n';
    cout << "Median:             " << median(a3, n) << '\n';
    cout << "Standard Deviation: " << stddev(a3, n) << '\n';
    cout << endl;

    return 0;
}
//*******************************************************************
//
//  solution.cpp
//  CSCI 241 Lab 1
//
//  Sam Normoyle (Z-ID: Z1980761)
//  Leang Y Chheav(Z-ID: Z1966108)
//
//*******************************************************************

#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::sqrt;
using std::pow;


int minimum(int array[], int n);
int maximum(int array[], int n);
int range(int array[], int n);
double average(int array[], int n);
double median(int array[], int n);
double stddev(int array[], int n);


int minimum(int array[], int n){
    double min_value = array[0];
    for(int i = 0; i < n; i++){
        if(array[i] < min_value){
            min_value = array[i];   
        }
    }

    return min_value;
}

int maximum(int array[], int n){
    double max_value = array[0];
    for(int i = 0; i < n; i++){
        if(array[i] > max_value){
            max_value = array[i];   
        }
    }

    return max_value;
}

int range(int array[], int n){
    double max = maximum(array, n);
    double min = minimum(array, n);

    return max - min;

}

double average(int array[], int n){
    double sum = 0;
    for(int i; i < n; i++){
        sum += array[i];
    }
    return sum/n;
}

double median(int array[], int n){
    double median;
    if(n%2 == 0){
        median = (array[(n/2)-1]+array[(n/2)])/2.00;
    }
    else{
        median = array[(n/2)+(1/2)];
    }

    return median;
}

double stddev(int array[], int n){
    double standard_dev;
    double mean = average(array, n);
    double temp;
    for(int i; i<n; i++){
        temp += pow((array[i]-mean),2);
    }
    temp = temp/n;
    standard_dev = sqrt(temp);
    return standard_dev;
}


// int minimum(int array[], int n){
//     int min_value = array[0];
//     for(int i = 0; i < n ; i++){
//         if(array[i] < min_value){
//             min_value = array[i];   
//         }
//     }

//     return min_value;
// }

// int maximum(int array[], int n){
//     int max_value = array[0];
//     for(int i = 0; i < n; i++){
//         if(array[i] > max_value){
//             max_value = array[i];  
//         }
//     }

//     return max_value;
// }

// int range(int array[], int n){
//     int max = maximum(array, n);
//     int min = minimum(array, n);

//     return max - min;
// }

// double average(int array[], int n){
//     double sum = 0;
//     for(int i = 0; i < n; i++){
//         sum += array[i];
//     }
//     return (sum/n);
// }

// double median(int array[], int n){
//     double median;
//     if(n%2 == 0){//{66, 68, 70, 72, 75, 84, 86, 86, 89};
//         median = (array[n/2] + array[(n/2)-1])/2.00;
//     }else{
//         median = (array[n/2]) - 1/2;
//     }

//     return median;
// }

// double stddev(int array[], int n){
//     int sum = 0;
//     int sum_square = 0; // (1+2)^2
//     int square_sum = 0; // (1^2 + 2^2)
//     double std = 0;
//     double variance = 0;
//     for(int i = 0; i < n; i++){
//         sum += array[i];
//     }
//     sum_square = pow(sum, 2);
//     cout << "sum square: "<< sum_square <<endl;

//     for(int i = 0; i < n; i++){
//         square_sum += pow(array[i], 2);
//     }
//     cout << "square sum: " << square_sum << endl;


//     variance = ((square_sum - (sum_square)/(double)n))/(n - 1);
//     std = sqrt(variance);
//     return std;
// }

