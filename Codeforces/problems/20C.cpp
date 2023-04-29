/* 20C. Dijkstra? */
// https://codeforces.com/problemset/problem/20/c
// Date: 2023-04-13 10:51:25
// Run time: 77 ms
// Memory: 10800 KB
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

vector<vector<ii>> AL;
vector<int> dist, path;

void solve() {
    int n, m;
    cin >> n >> m;
    AL.resize(n);
    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        AL[a].push_back({b, w});
        AL[b].push_back({a, w});
    }

    int s = 0, f = n - 1;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    dist.assign(n, 1e18);
    path.assign(n, -1);
    dist[s] = 0;
    pq.push({dist[s], s});

    while (!pq.empty()) {
        auto [wu, u] = pq.top();
        pq.pop();
        if (wu > dist[u]) continue;
        for (auto [v, w] : AL[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                path[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (path[f] == -1) {
        cout << -1 << endl;
    } else {
        vector<int> answ;
        int u = f;
        while (u != -1) {
            answ.push_back(u + 1);
            u = path[u];
        }
        for (auto it = answ.rbegin(); it != answ.rend(); it++) {
            cout << *it << ' ';
        }
        cout << endl;
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