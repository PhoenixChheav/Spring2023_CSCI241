#include <iostream>
#include <cstdlib>
// #include <cmath>
// #include <cstring>

using namespace std;

//6/7
// int max_stepnum(int n){
//      for(int i = n; i >= -1; i--){
//           int num = i;
//           bool stepnum = true;
//           while(num > 9){
//                int last = num % 10;
//                int second_last = (num/10) % 10;
//                if(abs(last - second_last) != 1){
//                     stepnum = false;
//                     break;
//                }
//                num /= 10;
//           }
//           if(stepnum){
//                return i;
//           }
//      }
//      return -1;
// }

// int max_stepnum(int n){
//      for(int i = n; i >= -1; i--){
//           int num = i;
//           bool step = true;
//           while(num > 9){
//                int last = num % 10;
//                int second_last = (num / 10) % 10;
//                if(abs(last - second_last) != 1){
//                     step = false;
//                     break;
//                }
//                num /= 10;
//           }
//           if(step){
//                return i;
//           }
//      }
//      return -1;
// }

//if it's -15 return -12
// int max_stepnum(int n) {
//     if (n < 0) {
//         return -max_stepnum(-n);
//     }
//     if (n < 10) {
//         return n;
//     }
//     for (int i = n; i >= 10; i--) {
//         int prev = i % 10;
//         int num = i / 10;
//         bool is_stepnum = true;
//         while (num > 0) {
//             int curr = num % 10;
//             if (abs(curr - prev) != 1) {
//                 is_stepnum = false;
//                 break;
//             }
//             prev = curr;
//             num /= 10;
//         }
//         if (is_stepnum) {
//             return i;
//         }
//     }
//     return -1;
// }

int max_stepnum(int n){
     for(int i = n-1; i >= -1; i--){
          int num = i;
          bool stepnum = true;
          while(num > 9){
               int last = num % 10;
               int second_last = (num/10) % 10;
               if(abs(last - second_last) != 1){
                    stepnum = false;
                    break;
               }
               num /= 10;
          }
          if(stepnum){
               return i;
          }
     }
     return -1;
}


int main(){
    int n1 = 15; // 12
    cout << "n = " << n1 << ", max stepnum = "
         << max_stepnum(n1) << endl;

    int n2 = 7; // 7
    cout << "n = " << n2 << ", max stepnum = "
         << max_stepnum(n2) << endl;

    int n3 = -15; // -21
    cout << "n = " << n3 << ", max stepnum = "
         << max_stepnum(n3) << endl;

    int n4 = 3406; // 3234
    cout << "n = " << n4 << ", max stepnum = "
         << max_stepnum(n4) << endl;

    return 0;
}
