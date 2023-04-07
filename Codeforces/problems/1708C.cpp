/* 1708C. Doremy's IQ */
// https://codeforces.com/contest/1708/problem/C
// Date: Jul/26/2022 14:15
// Run time: 156 ms
// Memory: 800 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int TC; cin >> TC;
    while (TC--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (auto&& ai : a) cin >> ai;

        vector<int> memo(n, 0);
        memo[n - 1] = 1;
        for (int i = n - 2; i > -1; i--) {
            memo[i] = memo[i + 1] + (a[i] > memo[i + 1] ? 1 : 0);
        }
        
        int i = 0;
        while (i < n) {
            if (memo[i] <= q) break;
            cout << (a[i] <= q ? 1 : 0);
            i++;
        }
        for (; i < n; i++) cout << 1;
        cout << endl;
    }
}