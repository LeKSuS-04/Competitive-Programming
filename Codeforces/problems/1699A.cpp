/* 1699A. The Third Three Number Problem  */
// https://codeforces.com/contest/1699/problem/A
// Date: Aug/02/2022 10:09
// Run time: 46 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int TC; cin >> TC;
    while (TC--) {
        int n;
        cin >> n;

        if (n & 1) cout << -1 << '\n';
        else cout << "69 69 " << ((n/2) ^ 69) << '\n';
    }
}