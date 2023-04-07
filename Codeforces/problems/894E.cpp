/* 894E. Ralph and Mushrooms */
// https://codeforces.com/problemset/problem/894/E
// Date: 2023-03-30 15:06:16
// Run time: 1247 ms
// Memory: 267600 KB
// Verdict: AC

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ll2;
typedef tuple<ll, ll, ll> ll3;

vector<vector<ll>> AL, sccs, scc_edge_weights;
vector<vector<ll2>> AL_sccs;
vector<ll3> edges;
vector<ll> dfs_num, dfs_low, dfs_stack, scc_num, scc_weight;
vector<char> dfs_on_stack;
ll dfs_count = 0, scc_count = 0;

void find_sccs(ll u) {
    dfs_num[u] = dfs_low[u] = dfs_count++;
    dfs_stack.push_back(u);
    dfs_on_stack[u] = true;

    for (auto&& v : AL[u]) {
        if (dfs_num[v] == -1) find_sccs(v);
        if (dfs_on_stack[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if (dfs_low[u] == dfs_num[u]) {
        while (true) {
            ll v = dfs_stack.back();
            dfs_stack.pop_back();
            dfs_on_stack[v] = false;
            scc_num[v] = scc_count;
            if (u == v) break;
        }
        ++scc_count;
    }
}

ll edge_weight(ll w) {
    ll l = 0, r = w;
    while (r - l > 1) {
        ll m = (r + l) / 2;
        if (m * (m + 1) / 2 > w) {
            r = m;
        } else {
            l = m;
        }
    }
    return w * (l + 1) - l * (l + 1) * (l + 2) / 6;
}

vector<char> visited;
vector<ll> order;
void toposort_sccs(int u) {
    visited[u] = true;
    for (auto&& [v, _] : AL_sccs[u]) {
        if (!visited[v]) {
            toposort_sccs(v);
        }
    }
    order.push_back(u);
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, s;
    cin >> n >> m;

    AL.resize(n);
    dfs_num.assign(n, -1);
    dfs_low.assign(n, -1);
    scc_num.assign(n, -1);
    dfs_on_stack.assign(n, false);

    while (m--) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        AL[u].push_back(v);
        edges.push_back({u, v, w});
    }

    cin >> s;
    --s;

    for (int i = 0; i < n; i++) {
        if (dfs_num[i] == -1) {
            find_sccs(i);
        }
    }

    scc_edge_weights.resize(scc_count);
    scc_weight.assign(scc_count, 0);
    for (auto&& [u, v, w] : edges) {
        if (scc_num[u] == scc_num[v]) {
            scc_edge_weights[scc_num[u]].push_back(w);
        }
    }
    for (int i = 0; i < scc_count; i++) {
        for (auto&& w : scc_edge_weights[i]) {
            scc_weight[i] += edge_weight(w);
        }
    }

    AL_sccs.resize(scc_count);
    visited.assign(scc_count, false);
    for (auto&& [u, v, w] : edges) {
        if (scc_num[u] != scc_num[v]) {
            AL_sccs[scc_num[u]].push_back({scc_num[v], w + scc_weight[scc_num[v]]});
        }
    }

    s = scc_num[s];
    vector<ll> dist(scc_count, -1);
    dist[s] = scc_weight[s];
    for (int i = 0; i < scc_count; i++) {
        if (!visited[i]) {
            toposort_sccs(i);
        }
    }
    reverse(order.begin(), order.end());

    for (auto&& u : order) {
        if (dist[u] == -1) continue;
        for (auto&& [v, w] : AL_sccs[u]) {
            dist[v] = max(dist[v], dist[u] + w);
        }
    }

    cout << *max_element(dist.begin(), dist.end()) << endl;
}