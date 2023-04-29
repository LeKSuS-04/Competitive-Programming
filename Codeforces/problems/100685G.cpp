/* 100685G. Gadget Hackwrench */
// https://codeforces.com/problemset/gymProblem/100685/G
// Date: 2023-04-12 11:51:29
// Run time: 420 ms
// Memory: 23068 KB
// Verdict: AC

#ifndef LOCALENV
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int logn;
vector<vector<int>> AL;
map<pair<int, int>, bool> is_forward;
vector<vector<int>> up;
vector<int> fwd, bwd;
vector<int> tin, tout;
int timer = 0;

void dfs(int u, int p) {
    tin[u] = ++timer;
    if (u != p) {
        fwd[u] = fwd[p];
        bwd[u] = bwd[p];
        if (is_forward[{p, u}]) {
            ++fwd[u];
        } else {
            ++bwd[u];
        }
    }
    up[u][0] = p;
    for (int i = 1; i <= logn; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for (int v : AL[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    tout[u] = ++timer;
}

bool is_ancestor(int p, int c) { return tin[p] <= tin[c] && tout[p] >= tout[c]; }

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

bool exists_way(int u, int v) {
    int l = lca(u, v);
    return (fwd[u] - fwd[l]) == 0 && (bwd[v] - bwd[l]) == 0;
}

void solve() {
    int n;
    cin >> n;

    AL.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        AL[u].push_back(v);
        AL[v].push_back(u);
        is_forward[{u, v}] = true;
        is_forward[{v, u}] = false;
    }

    int root = 0;
    fwd.resize(n);
    bwd.resize(n);
    fwd[root] = bwd[root] = 0;
    logn = ceil(log2(n));
    up.assign(n, vector<int>(logn + 1));
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    dfs(root, root);

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        cout << (exists_way(a, b) ? "Yes" : "No") << '\n';
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