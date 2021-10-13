/* A - Median Maximization */
// https://codeforces.com/contest/1566/problem/A
// Date: Sep/12/2021 17:48 (00:07:35)
// Runtime: 46 ms
// Memory: 3600 KB
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, s;
        cin >> n >> s;
        cout << s / (n - (n - 1)/2) << endl;
    }
}