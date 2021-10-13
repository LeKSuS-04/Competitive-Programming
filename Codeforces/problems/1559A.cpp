/* 1559A - Mocha and Math */
// https://codeforces.com/contest/1559/problem/A
// Date: Aug/23/2021 15:28
// Runtime: 46ms
// Memory: 3700 KB
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, a, ans = (1 << 30) - 1;
        cin >> n;

        while (n--) {
            cin >> a;
            ans &= a;
        }

        cout << ans << endl;
    }
}