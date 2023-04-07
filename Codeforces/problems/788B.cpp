/* 788B. Weird Journey */
// https://codeforces.com/problemset/problem/788/B
// Date: 2023-03-15 19:56:21
// Run time: 826 ms
// Memory: 84500 KB
// Verdict: AC

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> AL;
vector<ll> indegree;
vector<bool> visited;
vector<bool> has_loop;

void dfs(int u) {
    visited[u] = true;
    for (auto&& v : AL[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    AL.resize(n);
    indegree.assign(n, 0);
    has_loop.assign(n, false);
    ll loops = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        ++indegree[u], ++indegree[v];
        AL[u].push_back(v);
        AL[v].push_back(u);
        if (u == v) {
            has_loop[u] = true;
            ++loops;
        }
    }

    int scc_amount = 0;
    visited.assign(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i] && indegree[i] > 0) {
            scc_amount++;
            dfs(i);
        }
    }
    if (scc_amount > 1) {
        cout << 0 << endl;
        return 0;
    }

    ll answer = loops * (loops - 1) / 2;
    for (int i = 0; i < n; i++) {
        ll k = indegree[i];
        if (has_loop[i]) {
            k -= 1;
            answer += m - k - loops + 1;
        }
        answer += k * (k - 1) / 2;
    }
    cout << answer << endl;
}