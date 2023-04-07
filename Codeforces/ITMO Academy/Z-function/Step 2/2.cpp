/* B. Z-функция строки Грея */
// https://codeforces.com/edu/course/2/lesson/3/2/practice/contest/272261/problem/B
// Date: 20.08.2021 07:50
// Run time: 77 ms
// Memory: 3700 KB
// Verdict: AC

#include <iostream>
#include <string>
using namespace std;

int count_twos(int n) { return (n % 2 == 1 ? 0 : 1 + count_twos(n / 2)); }

int grey(int k, int j) {
    if (j == 0) return 0;
    return (1 << count_twos(j)) - 1;
}

int main() {
    int TC, k, j;
    cin >> TC;

    while (TC--) {
        cin >> k >> j;
        cout << grey(k, j) << endl;
    }
}