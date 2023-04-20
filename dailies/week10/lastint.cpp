#include <iostream>

using namespace std;

int last_int_standing(size_t n, size_t step);

int main()
{
    size_t n1 = 4, step1 = 1; // 1
    cout << "n = " << n1 << ", step = " << step1
         << ", last int standing = "
         << last_int_standing(n1, step1) << endl;

    size_t n2 = 4, step2 = 3; // 2
    cout << "n = " << n2 << ", step = " << step2
	     << ", last int standing = "
         << last_int_standing(n2, step2) << endl;

    size_t n3 = 6, step3 = 10; // 3
    cout << "n = " << n3 << ", step = " << step3
	     << ", last int standing = "
         << last_int_standing(n3, step3) << endl;

    size_t n4 = 1, step4 = 100; // 1
    cout << "n = " << n4 << ", step = " << step4
	     << ", last int standing = "
         << last_int_standing(n4, step4) << endl;

    return 0;
}

int last_int_standing(size_t n, size_t step) {
    int index = 0;
    vector<int> list(n);
    
    if (n == 0 || step == 0) {
        return -1;
    }

    for (int i = 0; i < n; i++) {
        list[i] = i + 1;
    }
    while (list.size() > 1) {
        index = (index + step) % list.size();
        list.erase(list.begin() + index);
    }
    
    return list[0];
}


// int last_int_standing(size_t n, size_t step){
//      if(n == 0 || step == 0){
//           return -1;
//      }

//      vector<int> list(n);
//      size_t idx = 0;
//      for(size_t i = 0; i < n; i++){
//           idx = (idx + step - 1) % list.size();
//           list.erase(list.begin() + idx);
//      }
//      return list;
// }

// int last_int_standing(size_t n, size_t step) {
//     if (n == 0 || step == 0) {
//         return -1; // invalid input
//     }
//     int rem = 1;
//     for(size_t i = 2; i <= n; i ++){
//         rem = (rem + step) % i;
//         if(rem == 0){
//             rem = i;
//         }
//     }
//     return rem;
// }

/***
 * 
 * In this example, the function takes in two arguments, n and step. It first checks if either argument is equal to 0. If so, it returns -1. Otherwise, it initializes a variable called remaining to 1. It then loops through each integer from 2 to n and updates the value of remaining based on the current integer and step size. Finally, it returns the value of remaining.
 * 
***/