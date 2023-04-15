/* 1820E. The Fox and the Complete Tree Traversal */
// https://codeforces.com/contest/1820/problem/E
// Date: 2023-04-15 13:52:20
// Run time: 187 ms
// Memory: 32460 KB
// Verdict: AC

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
vi indegree;
vector<vi> path(2, vi());

void dfs(int u, int i) {
    visited[u] = true;
    path[i].push_back(u + 1);
    for (int v : AL[u]) {
        if (!visited[v] && AL[v].size() == 1) {
            dfs(v, 1 - i);
        }
    }
    for (int v : AL[u]) {
        if (!visited[v]) {
            dfs(v, 1 - i);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    AL.assign(n, vi());
    indegree.assign(n, 0);
    visited.assign(n, false);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        AL[u].push_back(v);
        AL[v].push_back(u);
        ++indegree[u];
        ++indegree[v];
    }
    if (n == 2) {
        cout << "Yes\n1 2\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (AL[i].size() == 1) {
            --indegree[AL[i][0]];
            --indegree[i];
        }
    }
    vi ends;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 1) {
            ends.push_back(i);
        }
    }

    if (ends.size() > 2) {
        cout << "No\n";
        return;
    }
    if (ends.size() == 0) {
        cout << "Yes\n";
        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
        cout << endl;
        return;
    }

    int s;
    for (int v : AL[ends[0]]) {
        if (indegree[v] == 0) {
            s = v;
            break;
        }
    }
    path[0].clear();
    path[1].clear();
    dfs(s, 0);
    reverse(path[1].begin(), path[1].end());
    cout << "Yes\n";
    for (int a : path[0]) {
        cout << a << ' ';
    }
    for (int a : path[1]) {
        cout << a << ' ';
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