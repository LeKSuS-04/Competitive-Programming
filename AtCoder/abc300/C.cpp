#ifndef LOCALENV
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

/* C - Cross */
// https://atcoder.jp/contests/abc300/tasks/abc300_c
// Date: 2023-04-29 15:38:27
// Run time: 8 ms
// Memory: 3576 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// #define int ll
typedef pair<int, int> ii;
typedef vector<int> vi;

void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> zig(h, string(w, 0)), zag(h, string(w, 0)), c(h, string(w, 0));
    /*
         #
    ZIG:  #
           #
================
           #
    ZAG:  #
         #
    */

    for (auto&& row : c) {
        cin >> row;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (c[i][j] == '#') {
                zig[i][j] = 1;
                if (i != 0 && j != 0) {
                    zig[i][j] += zig[i - 1][j - 1];
                }
            }
        }
    }
    for (int i = h - 1; i >= 0; i--) {
        for (int j = 0; j < w; j++) {
            if (c[i][j] == '#') {
                zag[i][j] = 1;
                if (i != h - 1 && j != 0) {
                    zag[i][j] += zag[i + 1][j - 1];
                }
            }
        }
    }

    vi res(min(w, h), 0);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (zig[i][j] == zag[i][j] && zig[i][j] > 1) {
                res[zig[i][j] - 2]++;
            }
        }
    }
    for (auto&& t : res) {
        cout << t << ' ';
    }
}

signed main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC = 1;
    // cin >> TC;
    while (TC--) {
        solve();
    }
    cout.flush();
}