/* The 2022 Hangzhou Normal U Summer Trials: D. Tree Problem */
// https://codeforces.com/gym/103736/problem/D
// Date: Aug/02/2022 13:14
// Run time: 748 ms
// Memory: 21300 KB
// Verdict: AC
// Lang: GNU C++20 (64)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<ll> precomputed;
vector<char> visited;
vector<vector<int>> AL;
unordered_map<ll, int> weight;

ll hash_pair(pair<int, int> p) { return ( ((ll) p.first) << 32LL) + p.second; }

int dfs(int v) {
    int w = 1;
    visited[v] = 1;

    for (auto u : AL[v]) 
        if (visited[u] == 0) w += dfs(u);

    for (auto u : AL[v]) {
        if (visited[u] == 1) {
            weight[hash_pair({v, u})] = n - w;
            weight[hash_pair({u, v})] = w;
        }
    }

    visited[v] = 2;
    return w;
}

ll sum_pair_prod(vector<ll>& paths) {
    if (paths.size() == 1) return paths[0];
    
    ll sum_of_sq = 0;
    ll sum = 0;
    for (auto w : paths) {
        sum += w;
        sum_of_sq += w*w;
    }
    return (sum*sum - sum_of_sq) / 2;
}

int main() {
    cin >> n;

    AL.assign(n, vector<int>());
    visited.assign(n, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v; u--, v--;
        AL[u].push_back(v);
        AL[v].push_back(u);
    }

    dfs(0);

    precomputed.assign(n, 0);
    for (int v = 0; v < n; v++) {
        vector<ll> paths;
        for (auto u : AL[v])
            paths.push_back(weight[hash_pair({v, u})]);

        if (paths.size() == 1) precomputed[v] = paths[0];
        else precomputed[v] = sum_pair_prod(paths) + reduce(paths.begin(), paths.end(), 0, 
                                                            [](int a, int b) { return a + b; } );
    }

    int QC, q;
    cin >> QC;
    while (QC--) {
        cin >> q;
        cout << precomputed[q-1] << '\n';
    }
}