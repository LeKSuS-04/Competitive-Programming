/* 427C. Checkposts */
// https://codeforces.com/problemset/problem/427/C
// Date: 2023-03-30 11:31:54
// Run time: 951 ms
// Memory: 19200 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

vector<vector<ll>> AL, sccs;
vector<ll> dfs_num, dfs_low, dfs_stack;
vector<bool> dfs_on_stack;
ll dfs_count = 0;

void find_sccs(ll u) {
    dfs_num[u] = dfs_low[u] = dfs_count++;
    dfs_stack.push_back(u);
    dfs_on_stack[u] = true;

    for (auto&& v : AL[u]) {
        if (dfs_num[v] == -1) find_sccs(v);
        if (dfs_on_stack[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if (dfs_low[u] == dfs_num[u]) {
        sccs.push_back(vector<ll>());
        while (true) {
            ll v = dfs_stack.back();
            dfs_stack.pop_back();
            dfs_on_stack[v] = false;
            sccs.back().push_back(v);
            if (u == v) break;
        }
    }
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif

    ll n;
    cin >> n;

    vector<ll> price(n);
    for (auto&& p : price) cin >> p;

    AL.resize(n);
    dfs_num.assign(n, -1);
    dfs_low.assign(n, -1);
    dfs_on_stack.assign(n, false);

    ll m;
    cin >> m;
    while (m--) {
        ll u, v;
        cin >> u >> v;
        --u, --v;
        AL[u].push_back(v);
    }

    for (ll i = 0; i < n; i++) {
        if (dfs_num[i] == -1) find_sccs(i);
    }

    ll min_cost = 0;
    ll variants = 1;
    for (auto&& scc : sccs) {
        ll min_cost_local = price[*min_element(scc.begin(), scc.end(),
                                               [&](ll v, ll u) { return price[v] < price[u]; })];
        min_cost += min_cost_local;
        variants =
            variants *
            count_if(scc.begin(), scc.end(), [&](ll u) { return price[u] == min_cost_local; }) %
            MOD;
    }

    cout << min_cost << ' ' << variants << endl;
}