/* G. Bugged system */
// Date: 2023-03-15 20:17:37
// Run time: 702 ms
// Memory: 11948 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> x(n);
    for (auto&& xi : x) cin >> xi;

    vector<ll> indegree(n, 0), outdegree(n, 0);
    vector<pair<ll, ll>> edges;
    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        --u, --v;
        edges.push_back({u, v});
        ++indegree[v];
        ++outdegree[u];
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] != outdegree[i]) {
            cout << -1 << endl;
            return;
        }
    }

    ll answer = 0;
    for (auto&& [u, v] : edges) {
        answer += abs(x[u] - x[v]);
    }
    cout << answer << endl;
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#else
    freopen("bugged.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
}