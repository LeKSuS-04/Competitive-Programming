/* 1814B. Long Legs */
// https://codeforces.com/problemset/problem/1814/B
// Date: 2023-04-14 23:11:11
// Run time: 15 ms
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
#define int ll
typedef pair<int, int> ii;
typedef vector<int> vi;

void solve() {
    int a, b;
    cin >> a >> b;

    auto steps = [a, b](int m) { return (a + m - 1) / m + (b + m - 1) / m + m - 1; };

    int l = 1, r = 1e18;
    while (r - l > 1000) {
        int m1 = l + (r - l) / 3;
        int m2 = l + (r - l) * 2 / 3;
        if (steps(m1) < steps(m2)) {
            r = m2;
        } else {
            l = m1;
        }
    }
    int mn = 1e18;
    for (int i = max(l - 100, 1LL); i <= r + 100; i++) {
        mn = min(mn, steps(i));
    }

    cout << mn << '\n';
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