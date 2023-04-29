/* D - Цветные волшебники */
// Date: 2023-04-10 23:24:25
// Run time: 560 ms
// Memory: 31200KB
// Verdict: AC

#ifndef LOCALENV
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        uintmax_t hash = std::hash<T1>{}(p.first);
        hash <<= sizeof(uintmax_t) * 4;
        hash ^= std::hash<T2>{}(p.second);
        return std::hash<uintmax_t>{}(hash);
    }
};

vector<vector<int>> AL, ALc, up;
vector<int> tin, tout, low, scc_num, dist;
vector<char> visited;
vector<pair<int, int>> edges;
unordered_set<pair<int, int>, hash_pair> articulation_bridges;
int timer = 0, root, scc_amount = 0, logn;

void bfs(int start) {
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : AL[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

void find_articulation_points(int u, int p = -1) {
    tin[u] = low[u] = timer++;
    visited[u] = true;
    for (auto v : AL[u]) {
        if (!visited[v]) {
            find_articulation_points(v, u);
            if (low[v] > tin[u]) {
                articulation_bridges.insert({u, v});
                articulation_bridges.insert({v, u});
            }
            low[u] = min(low[u], low[v]);
        } else if (v != p) {
            low[u] = min(low[u], tin[v]);
        }
    }
}

void find_scc(int u, int p, int scc) {
    visited[u] = true;
    for (auto v : AL[u]) {
        if (!visited[v]) {
            if (articulation_bridges.find({u, v}) != articulation_bridges.end()) {
                ++scc_amount;
                scc_num[v] = scc_amount;
                find_scc(v, u, scc_amount);
            } else {
                scc_num[v] = scc;
                find_scc(v, u, scc);
            }
        }
    }
}

void build_lca(int u, int p) {
    tin[u] = timer++;
    up[u][0] = p;

    for (int i = 1; i <= logn; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for (auto v : AL[u]) {
        if (v != p) {
            build_lca(v, u);
        }
    }

    tout[u] = timer++;
}

bool is_ancestor(int p, int c) { return tin[c] >= tin[p] && tout[c] <= tout[p]; }

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = logn; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

void solve() {
    int n, m;
    cin >> n >> m;
    AL.resize(n);
    tin.resize(n);
    low.resize(n);
    scc_num.resize(n);

    cin >> root;
    root--;

    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        AL[u].push_back(v);
        AL[v].push_back(u);
        edges.push_back({u, v});
    }

    visited.assign(n, false);
    find_articulation_points(root);
    visited.assign(n, false);
    scc_num[root] = 0;
    find_scc(root, -1, scc_amount);
    ++scc_amount;

    ALc.resize(scc_amount);
    for (auto [u, v] : edges) {
        u = scc_num[u];
        v = scc_num[v];
        if (u != v) {
            ALc[u].push_back(v);
            ALc[v].push_back(u);
        }
    }

#ifdef LOCALENV
    for (int i = 0; i < ALc.size(); i++) {
        cout << '[' << i << "]: " << (ALc[i].size() == 0 ? "empty" : to_string(ALc[i][0]));
        for (int j = 1; j < ALc[i].size(); j++) {
            cout << ", " << AL[i][j];
        }
        cout << '\n';
    }
    cout << "=================\n";
#endif

    swap(AL, ALc);
    root = scc_num[root];
    timer = 0;
    tin.resize(scc_amount);
    tout.resize(scc_amount);
    logn = ceil(log2(scc_amount));
    up.resize(scc_amount, vector<int>(logn + 1));
    build_lca(root, root);

    dist.resize(n);
    visited.assign(n, false);
    bfs(root);

    int k;
    cin >> k;
    while (k--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        u = scc_num[u];
        v = scc_num[v];
        int l = lca(u, v);
        cout << dist[l] << '\n';
    }
}

signed main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
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