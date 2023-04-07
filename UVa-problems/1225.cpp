/* UVa 1225 - Digit Counting */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3666
// Date: 2021-09-11 11:14:32
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <string.h>
using namespace std;

void count_digits(int n, int* digits) {
    while (n != 0) {
        ++digits[n % 10];
        n /= 10;
    }
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, digits[10];
        cin >> n;

        memset(digits, 0, sizeof digits);
        for (int i = 1; i <= n; i++)
            count_digits(i, digits);

        cout << digits[0];
        for (int i = 1; i < 10; i++)
            cout << " " << digits[i];
        cout << endl;
    }
}