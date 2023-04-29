/* 832D. Misha, Grisha and Underground */
// https://codeforces.com/problemset/problem/832/D
// Date: 2023-04-11 22:40:20
// Run time: 19400 KB
// Memory: 358 ms
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
vector<vector<int>> AL, up;
vector<int> tin, tout, dist;
int timer = 0;

void build_lca(int u, int p) {
    tin[u] = timer++;
    up[u][0] = p;
    for (int i = 1; i <= logn; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for (auto&& v : AL[u]) {
        if (v != p) {
            build_lca(v, u);
        }
    }

    tout[u] = timer++;
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

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto&& v : AL[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int get_dist(int a, int b) {
    int l = lca(a, b);
    return dist[a] + dist[b] - 2 * dist[l];
}

int check_order(int goal, int a, int b) {
    int l = lca(a, b);
    if (is_ancestor(l, goal)) {
        int lca_b = lca(b, goal), lca_a = lca(a, goal);
        if (get_dist(lca_a, goal) < get_dist(lca_b, goal)) {
            l = lca_a;
        } else {
            l = lca_b;
        }
    }
    return get_dist(l, goal) + 1;
}

void solve() {
    int n, q;
    cin >> n >> q;
    AL.resize(n);

    for (int i = 1; i < n; i++) {
        int pi;
        cin >> pi;
        --pi;
        AL[i].push_back(pi);
        AL[pi].push_back(i);
    }

    int root = 0;
    tin.resize(n);
    tout.resize(n);
    logn = ceil(log2(n));
    up.assign(n, vector<int>(logn + 1));
    build_lca(root, root);

    dist.assign(n, -1);
    bfs(root);

    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b, --c;
        cout << max(check_order(a, b, c), max(check_order(b, c, a), check_order(c, a, b))) << '\n';
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