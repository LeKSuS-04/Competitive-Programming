/* 1512A. Spy Detected! */
// https://codeforces.com/contest/1512/problem/A
// Date: Sep/17/2022 14:55
// Run time: 0 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int TC;
    cin >> TC;

    while (TC--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto&& ai : a) cin >> ai;

        for (int i = 0; i < n; i++) {
            if (a[i] != a[(n + i - 1) % n] && a[i] != a[(i + 1) % n]) {
                cout << i + 1 << endl;
                break;
            }
        }
    }
}