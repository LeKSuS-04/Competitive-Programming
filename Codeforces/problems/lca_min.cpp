/* A. LCA Запрос минимума */
// Date: 2023-04-02 13:30:52
// Run time: 3680 ms
// Memory: 25132 KB
// Verdict: AC

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, log_n;
vector<vector<ll>> up, AL;
vector<ll> tin, tout;
ll timer = 0;

void build(ll u, ll p) {
    tin[u] = timer++;
    up[u][0] = p;
    for (ll i = 1; i <= log_n; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for (ll v : AL[u]) {
        if (v != p) {
            build(v, u);
        }
    }
    tout[u] = timer++;
}

bool is_ancestor(ll p, ll c) { return tin[p] <= tin[c] && tout[p] >= tout[c]; }

ll lca(ll u, ll v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (ll i = log_n; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif
#ifdef ONLINE_JUDGE
    freopen("lca_rmq.in", "r", stdin);
    freopen("lca_rmq.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    log_n = ceil(log2(n));

    up.assign(n, vector<ll>(log_n + 1, 0));
    AL.resize(n);
    tin.resize(n);
    tout.resize(n);

    for (ll i = 1; i < n; i++) {
        ll pi;
        cin >> pi;
        AL[i].push_back(pi);
        AL[pi].push_back(i);
    }

    build(0, 0);

    ll a1, a2, a3, a4, x, y, z;
    cin >> a1 >> a2 >> x >> y >> z;
    auto next_a = [&x, &y, &z, n = n](ll ai_2, ll ai_1) {
        return (x * ai_2 % n + y * ai_1 % n + z) % n;
    };

    ll res = 0, v = 0;
    while (m--) {
        v = lca((a1 + v) % n, a2);
        res += v;
        a3 = next_a(a1, a2);
        a4 = next_a(a2, a3);
        a1 = a3;
        a2 = a4;
    }

    cout << res << endl;
}