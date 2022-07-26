/* 1708A. Difference Operations */
// https://codeforces.com/contest/1708/problem/A
// Date: Jul/26/2022 12:22
// Run time: 31 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, k, a;
        cin >> n >> k;

        bool can = true;
        while (--n) {
            cin >> a;
            can &= a % k == 0;
        }

        cout << (can ? "YES" : "NO") << "\n";
    }
}