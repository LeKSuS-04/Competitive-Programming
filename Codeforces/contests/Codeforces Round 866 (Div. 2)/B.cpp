/* 1820A. JoJo's Incredible Adventures */
// https://codeforces.com/contest/1820/problem/B
// Date: 2023-04-15 12:26:33
// Run time: 46 ms
// Memory: 1044 KB
// Verdict: AC

#ifndef LOCALENV
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
typedef pair<int, int> ii;
typedef vector<int> vi;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int lm = 0, l = 0;
    s += s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            lm = max(l, lm);
            l = 0;
        } else {
            l += 1;
        }
    }
    lm = max(l, lm);
    lm = min(lm, n);
    l = 0;

    if (lm == n) {
        cout << n * n << endl;
    } else {
        lm += 1;
        cout << (lm / 2) * ((lm + 1) / 2) << endl;
    }
}

signed main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC = 1;
    cin >> TC;
    while (TC--) {
        solve();
    }
    cout.flush();
}