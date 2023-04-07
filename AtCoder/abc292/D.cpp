/* D - Unicyclic Components */
// https://atcoder.jp/contests/abc292/tasks/abc292_d
// Date: 2023-03-04 15:16:06
// Run time: 131 ms
// Memory: 20548 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int vertices, edges;
vector<char> visited;
vector<vector<int>> AL;

void dfs(int u) {
    if (visited[u]) return;
    visited[u] = true;
    ++vertices;

    for (auto&& v : AL[u]) {
        dfs(v);
        ++edges;
    }
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;

    AL.resize(n);
    visited.assign(n, false);
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        AL[u].push_back(v);
        AL[v].push_back(u);
    }

    bool good = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vertices = edges = 0;
            dfs(i);
            edges /= 2;
            good &= vertices == edges;
        }
    }

    cout << (good ? "Yes" : "No") << endl;
}