/* 1328B. K-th Beautiful Stirng */
// https://codeforces.com/problemset/problem/1328/B
// Date: 2022-10-28 10:19:31
// Run time: 62 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;


ull f(ull n) {
    return n * (n + 1) / 2 + 1;
}

int main() {
    #ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
    #endif
    
    int TC;
    cin >> TC;

    while (TC--) {
        int n, k;
        cin >> n >> k;

        ull l = 0, r = 1e5 + 10;
        while (r - l > 1) {
            ull m = (r + l) / 2;
            if (f(m) <= k) l = m;
            else r = m;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (i == l + 1 || i == k - f(l)) {
                cout << 'b';
            } else {
                cout << 'a';
            }
        }
        cout << endl;
    }
}