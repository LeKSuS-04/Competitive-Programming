/* 1699B. Almost Ternary Matrix  */
// https://codeforces.com/contest/1699/problem/B
// Date: Aug/02/2022 10:38
// Run time: 31 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int TC; cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ((i + j + 1) % 4 == 0 || abs(i - j) % 4 == 0) << ' ';
            }
            cout << '\n';
        }
    }
}