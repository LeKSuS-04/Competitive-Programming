#ifndef LOCALENV
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// #define int ll
typedef pair<int, int> ii;
typedef vector<int> vi;

vector<vi> AL;
vector<char> visited;

int dfs(int u) {
    visited[u] = true;
    int res = 1;
    for (int v : AL[u]) {
        if (!visited[v]) {
            res += dfs(v);
        }
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;

    AL.assign(n, vi());
    while (m--) {
        int a, b;
        cin >> a >> b;
        --b, --a;
        AL[b].push_back(a);
    }

    visited.assign(n, false);
    if (dfs(0) != n) {
        cout << "INFINITE\n";
        return;
    }
    cout << "FINITE\n";

    
}

signed main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC = 1;
    cin >> TC;
    while (TC--) {
        solve();
    }
    cout.flush();
}