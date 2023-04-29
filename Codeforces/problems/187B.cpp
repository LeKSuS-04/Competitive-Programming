/* 187B. AlgoRace */
// https://codeforces.com/problemset/problem/187/b
// Date: 2023-04-13 13:12:11
// Run time: 216 ms
// Memory: 2088 KB
// Verdict: AC

#ifndef LOCALENV
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9;

void solve() {
    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<vector<int>>> AMs(m, vector<vector<int>>(n, vector<int>(n)));

    for (auto&& AM : AMs) {
        for (auto&& row : AM) {
            for (auto&& cell : row) {
                cin >> cell;
            }
        }
    }
    for (int car = 0; car < m; car++) {
        for (int i = 0; i < n; i++) {
            for (int s = 0; s < n; s++) {
                for (int f = 0; f < n; f++) {
                    AMs[car][s][f] = min(AMs[car][s][f], AMs[car][s][i] + AMs[car][i][f]);
                }
            }
        }
    }

    vector<vector<vector<int>>> best_way(n, vector<vector<int>>(n, vector<int>(n, INF)));
    for (int car = 0; car < m; car++) {
        for (int s = 0; s < n; s++) {
            for (int f = 0; f < n; f++) {
                best_way[0][s][f] = min(best_way[0][s][f], AMs[car][s][f]);
            }
        }
    }

    for (int changes = 1; changes < n; changes++) {
        for (int i = 0; i < n; i++) {
            for (int s = 0; s < n; s++) {
                for (int f = 0; f < n; f++) {
                    best_way[changes][s][f] = min(best_way[changes][s][f],
                                                  best_way[changes - 1][s][i] + best_way[0][i][f]);
                }
            }
        }
    }

    while (r--) {
        int s, t, k;
        cin >> s >> t >> k;
        --s, --t;
        k = min(k, n - 1);
        cout << best_way[k][s][t] << '\n';
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