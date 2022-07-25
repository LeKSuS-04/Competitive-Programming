/* 1711A. Perfect Permutation */
// https://codeforces.com/contest/1711/problem/A
// Date: Jul/25/2022 10:43
// Run time: 31 ms
// Memory: 0 KB
// Verdict: AC

#include <iostream>
using namespace std;

int main() {
    int TC, n;
    cin >> TC;
    while (TC--) {
        cin >> n;
        cout << n;
        for (int i = 1; i < n; i++) 
            cout << ' ' << i;
        cout << endl;
    }
}