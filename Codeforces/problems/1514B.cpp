/* 1514B. AND 0, Sum Big */
// https://codeforces.com/problemset/problem/1514/B
// Date: 2022-10-28 11:00:51
// Run time: 15 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const ull MOD = 1e9 + 7;

ull qpow(ull n, ull k) {
    if (k == 0) return 1;
    if (k & 1) return n * qpow(n, k - 1) % MOD;
    else return qpow(n * n % MOD, k/2);
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
        cout << qpow(n, k) << endl;
    }
}