// Verdict: AC

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

vi root;
vector<char> visited;
vector<vi> children;
vector<vi> AL;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    AL.assign(n, vi());
    visited.assign(n, 0);
    children.assign(n, vi());
    root.assign(n, -1);

    while (k--) {
        int c;
        cin >> c;
        int r = -1;
        while (c--) {
            int v;
            cin >> v;
            --v;
            if (r == -1) {
                r = v;
            }
            children[r].push_back(v);
            root[v] = r;
        }
    }

    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        AL[u].push_back(v);
        AL[v].push_back(u);
    }

    queue<int> q;
    vector<int> dist(n, -1);
    q.push(n - 1);
    dist[n - 1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : AL[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
        
        if (!visited[root[u]]) {
            for (int v : children[root[u]]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        visited[root[u]] = true;
    }

    for (int i = 0; i < n; i++) {
        cout << dist[i]  << ' ';
    }
    cout << endl;
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