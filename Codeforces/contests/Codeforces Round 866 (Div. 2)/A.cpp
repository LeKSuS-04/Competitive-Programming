/* 1820A. Yura's New Name */
// https://codeforces.com/contest/1820/problem/A
// Date: 2023-04-15 12:11:37
// Run time: 0 ms
// Memory: 8 KB
// Verdict: AC

#ifndef LOCALENV
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// #define int ll
typedef pair<int, int> ii;
typedef vector<int> vi;

void solve() {
    string s;
    cin >> s;
    if (s == "^") {
        cout << 1 << endl;
        return;
    }
    int answ = 0;
    if (s[0] == '_') {
        s = '^' + s;
        answ += 1;
    }
    if (s[s.size() - 1] == '_') {
        s = s + '^';
        answ += 1;
    }
    int c = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '^') {
            answ += max(c - 1, 0);
            c = 0;
        } else {
            c += 1;
        }
    }
    cout << answ << endl;
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