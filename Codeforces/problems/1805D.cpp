/* 1805D. A Wide, Wide Graph */
// https://codeforces.com/contest/1805/problem/D
// Date: 2023-04-03 19:23:54
// Run time: 124 ms
// Memory: 9300 KB
// Verdict: AC (After contest)

#ifndef LOCALENV
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AL;
vector<int> dist_from_x, dist_from_y;

void dfs(int u, vector<int>& dist) {
    for (auto&& v : AL[u]) {
        if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            dfs(v, dist);
        }
    }
}

int farthest_from(int u, vector<int>& dist) {
    dist.assign(AL.size(), -1);
    dist[u] = 0;
    dfs(u, dist);
    auto it = max_element(dist.begin(), dist.end());
    return distance(dist.begin(), it);
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    AL.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        AL[u].push_back(v);
        AL[v].push_back(u);
    }

    int x = farthest_from(0, dist_from_y);
    int y = farthest_from(x, dist_from_x);
    farthest_from(y, dist_from_y);
    int d = dist_from_x[y];

    vector<int> dist(n);
    for (int i = 0; i < n; i++) {
        dist[i] = max(dist_from_x[i], dist_from_y[i]);
    }

    vector<int> dist_count(n, 0);
    for (auto&& di : dist) {
        ++dist_count[di];
    }
    dist_count[d] -= 1;

    vector<int> answ(n);
    answ.back() = n;
    for (int i = n - 2; i >= 0; i--) {
        answ[i] = answ[i + 1] - dist_count[i + 1];
    }

    for (auto&& a : answ) {
        cout << a << ' ';
    }
    cout << endl;
}