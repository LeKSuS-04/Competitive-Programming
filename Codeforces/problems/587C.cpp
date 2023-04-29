/* 587C. Duff in the Army */
// https://codeforces.com/problemset/problem/587/C
// Date: 2023-04-12 20:26:25
// Run time: 2324 ms
// Memory: 205340 KB
// Verdict: AC

#ifndef LOCALENV
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int MAX_A = 10;

struct Mins {
    vector<int> values;

    Mins(const vector<int>& vals = {}) {
        for (auto it = vals.begin(); it != vals.end() && values.size() < MAX_A; it++) {
            values.push_back(*it);
        }
    }

    friend Mins merge(const Mins& a, const Mins& b) {
        Mins res;
        auto i = a.values.begin();
        auto j = b.values.begin();
        auto insert_a = [&]() {
            if (find(res.values.begin(), res.values.end(), *i) == res.values.end()) {
                res.values.push_back(*i);
            }
            ++i;
        };
        auto insert_b = [&]() {
            if (find(res.values.begin(), res.values.end(), *j) == res.values.end()) {
                res.values.push_back(*j);
            }
            ++j;
        };
        while (res.values.size() < MAX_A && (i != a.values.end() || j != b.values.end())) {
            if (i == a.values.end()) {
                insert_b();
            } else if (j == b.values.end()) {
                insert_a();
            } else {
                if (*i < *j) {
                    insert_a();
                } else {
                    insert_b();
                }
            }
        }
        return res;
    }
};

struct Lift {
    int p;
    Mins m;
};

int logn;
vector<vector<int>> AL;
vector<vector<int>> town;
vector<vector<Lift>> up;
vector<int> tin, tout;
int timer = 0;

void build_lca(int u, int p) {
    tin[u] = timer++;
    up[u][0].p = p;
    up[u][0].m = Mins(town[u]);

    for (int i = 1; i <= logn; i++) {
        int t = up[u][i - 1].p;
        up[u][i].p = up[t][i - 1].p;
        up[u][i].m = merge(up[u][i - 1].m, up[t][i - 1].m);
    }

    for (int v : AL[u]) {
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
        if (!is_ancestor(up[u][i].p, v)) {
            u = up[u][i].p;
        }
    }
    return up[u][0].p;
}

void answer_query(int u, int v, size_t a) {
    int l = lca(u, v);
    Mins m(town[l]);
    for (int cur : {u, v}) {
        if (cur == l) continue;
        for (int i = logn; i >= 0; i--) {
            if (!is_ancestor(up[cur][i].p, l)) {
                m = merge(m, up[cur][i].m);
                cur = up[cur][i].p;
            }
            m = merge(m, up[cur][0].m);
        }
    }

    cout << min(a, m.values.size());
    auto it = m.values.begin();
    for (int i = 0; i < min(a, m.values.size()); i++) {
        cout << ' ' << *it;
        it++;
    }
    cout << '\n';
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    AL.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        AL[u].push_back(v);
        AL[v].push_back(u);
    }

    town.resize(n);
    for (int p = 1; p <= m; p++) {
        int c;
        cin >> c;
        --c;
        town[c].push_back(p);
    }
    for (auto&& t : town) {
        sort(t.begin(), t.end());
    }

    int root = 0;
    tin.resize(n);
    tout.resize(n);
    logn = ceil(log2(n));
    up.resize(n, vector<Lift>(logn + 1));
    build_lca(root, root);

    while (q--) {
        int u, v, a;
        cin >> u >> v >> a;
        --u, --v;
        answer_query(u, v, a);
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