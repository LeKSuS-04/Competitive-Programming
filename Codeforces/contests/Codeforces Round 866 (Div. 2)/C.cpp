/* 1820C. Constructive Problem */
// https://codeforces.com/contest/1820/problem/C
// Date: 2023-04-15 12:45:54
// Run time: 78 ms
// Memory: 10748 KB
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
    int n;
    cin >> n;
    vector<int> a;
    unordered_set<int> au;
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        a.push_back(ai);
        au.insert(ai);
    }

    int mex = 0;
    for (int i = 0; i <= n; i++) {
        if (au.count(i) == 0) {
            mex = i;
            break;
        }
    }

    if (mex == 0) {
        cout << "Yes\n";
        return;
    }

    set<int> bigger_idxs;
    for (int i = 0; i < n; i++) {
        if (a[i] == mex + 1) {
            bigger_idxs.insert(i);
        }
    }
    if (bigger_idxs.size() == 0) {
        if (mex == n) {
            cout << "No\n";

        } else {
            cout << "Yes\n";
        }
        return;
    }

    int s = *bigger_idxs.begin();
    int f = *bigger_idxs.rbegin();
    for (int i = s; i <= f; i++) {
        a[i] = mex;
    }

    au.clear();
    for (int ai : a) {
        au.insert(ai);
    }
    int mex2 = 0;
    for (int i = 0; i <= n; i++) {
        if (au.count(i) == 0) {
            mex2 = i;
            break;
        }
    }
    if (mex2 == mex + 1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
