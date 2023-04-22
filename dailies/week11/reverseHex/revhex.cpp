#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int reverse_hex(int n) {
    if(n < 0) {
        return -1;
    }
    string hex = "";
    while (n != 0) {
        int rem = n % 16;
        if (rem < 10) {
            hex = to_string(rem) + hex;
        } else {
            hex = char(rem - 10 + 'A') + hex;
        }
        n /= 16;
    }

    string rev_hex = "";
    for (int i = hex.length() - 1; i >= 0; i--) {
        rev_hex += hex[i];
    }

    int result = 0;
    int base = 1;
    for (int i = rev_hex.length() - 1; i >= 0; i--) {
        if (isdigit(rev_hex[i])) {
            result += (rev_hex[i] - '0') * base;
        } else {
            result += (rev_hex[i] - 'A' + 10) * base;
        }
        base *= 16;
    }

    return result;
}

int main()
{
    cout << "n = " << -10 << ", reverse_hex = " << reverse_hex(-10) << endl;
    cout << "n = " << 18 << ", reverse_hex = " << reverse_hex(18) << endl;
    cout << "n = " << 17 << ", reverse_hex = " << reverse_hex(17) << endl;
    cout << "n = " << 1 << ", reverse_hex = " << reverse_hex(1) << endl;
    cout << "n = " << 0 << ", reverse_hex = " << reverse_hex(0) << endl;
    cout << "n = " << 11 << ", reverse_hex = " << reverse_hex(11) << endl;
    cout << "n = " << 16 << ", reverse_hex = " << reverse_hex(16) << endl;
    cout << "n = " << 8612 << ", reverse_hex = " << reverse_hex(8612) << endl;

    return 0;
}