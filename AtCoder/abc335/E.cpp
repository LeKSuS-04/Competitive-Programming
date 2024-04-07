// #ifndef LOCALENV
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// #define int ll
typedef pair<int, int> ii;
typedef vector<int> vi;

vector<char> visited, connects_to_source;
vector<int> a, cost;
vector<vi> AL;

void dfs(int v) {
    visited[v] = true;
    for (const auto& u : AL[v]) {
        if (a[u] <= a[v]) {
            if (!visited[u]) {
                dfs(u);
            }

            if (connects_to_source[u]) {
                connects_to_source[v] = true;
                cost[v] = max(cost[v], cost[u] + (a[u] == a[v] ? 0 : 1));
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    AL.resize(n);
    a.resize(n);
    for (auto&& ai : a) cin >> ai;
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        AL[u].push_back(v);
        AL[v].push_back(u);
    }

    visited.assign(n, false);
    connects_to_source.assign(n, false);
    connects_to_source[0] = true;
    cost.assign(n, 0);
    cost[0] = 1;
    dfs(n - 1);

    if (visited[0] == false) {
        cout << 0 << endl;
        return;
    }

    cout << cost[n - 1] << endl;
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