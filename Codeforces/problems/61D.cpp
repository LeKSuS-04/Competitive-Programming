/* 61D. Eternal Victory */
// https://codeforces.com/problemset/problem/61/D
// Date: 2023-03-14 23:44:48
// Run time: 8600 KB
// Memory: 390 ms
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

vector<vector<pair<ll, ll>>> AL;
vector<ll> indegree;
vector<bool> visited;

ll longest_path_from_vertex(ll u) {
    visited[u] = true;

    ll longest = 0;
    for (auto&& [v, w] : AL[u]) {
        if (!visited[v]) {
            longest = max(longest, w + longest_path_from_vertex(v));
        }
    }
    return longest;
}

int main() {
    ll n;
    cin >> n;

    AL.resize(n);
    indegree.assign(n, 0);
    visited.assign(n, false);

    ll total_w = 0;
    for (ll i = 0; i < n - 1; i++) {
        ll x, y, w;
        cin >> x >> y >> w;
        --x, --y;
        total_w += w;
        AL[x].push_back({y, w});
        ++indegree[x];
        AL[y].push_back({x, w});
        ++indegree[y];
    }

    cout << 2 * total_w - longest_path_from_vertex(0) << endl;
}