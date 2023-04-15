/* C - Cards Query Problem */
// https://atcoder.jp/contests/abc298/tasks/abc298_c
// Date: 2023-04-15 15:12:38
// Run time: 202 ms
// Memory: 36972 KB
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

const int MAX_N = 2e5 + 100;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<set<int>> ntob(MAX_N);
    vector<multiset<int>> bton(MAX_N);
    while (q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int i, j;
            cin >> i >> j;
            bton[j].insert(i);
            ntob[i].insert(j);
        } else if (cmd == 2) {
            int i;
            cin >> i;
            for (int t : bton[i]) {
                cout << t << ' ';
            }
            cout << endl;
        } else if (cmd == 3) {
            int i;
            cin >> i;
            for (int t : ntob[i]) {
                cout << t << ' ';
            }
            cout << endl;
        }
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