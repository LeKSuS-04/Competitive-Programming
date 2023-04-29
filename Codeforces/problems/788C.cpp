/* 788C. The Great Mixing */
// https://codeforces.com/problemset/problem/788/C
// Date: 2023-04-14 22:53:07
// Run time: 155 ms
// Memory: 100 KB
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

const int MAX_N = 1000;
const int INF = 1e9;

void solve() {
    int n, k;
    cin >> n >> k;
    unordered_set<int> a;
    while (k--) {
        int ai;
        cin >> ai;
        a.insert(ai - n);
    }

    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());
    if (mn > 0 || mx < 0) {
        cout << -1 << endl;
        return;
    }

    vector<int> dist((MAX_N + 1) * 2, INF);
    queue<int> q;
    for (int ai : a) {
        q.push(ai);
        dist[ai + MAX_N] = 1;
    }

    while (dist[0 + MAX_N] == INF) {
        int u = q.front();
        q.pop();
        for (int ai : a) {
            int v = u + ai;
            if (abs(v) <= MAX_N && dist[u + MAX_N] + 1 < dist[v + MAX_N]) {
                dist[v + MAX_N] = dist[u + MAX_N] + 1;
                q.push(v);
            }
        }
    }

    cout << dist[0 + MAX_N] << endl;
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