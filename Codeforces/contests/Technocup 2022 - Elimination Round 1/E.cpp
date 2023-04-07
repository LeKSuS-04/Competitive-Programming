/* E - Moment of Bloom */
// https://codeforces.com/contest/1583/problem/E
// Date: Oct/17/2021 16:19 (02:14:14)
// Runtime: 0 ms
// Memory: 100 KB
// Verdict: WA

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;

int src, dst;
bool found_way = false;
vector<int> p;
vector<int> visited;
vector<vector<int>> AM;
vector<vector<int>> AL;

void dfs(int u) {
    if (u == dst) found_way = true;
    else {
        visited[u] = true;

        for (auto&& v : AL[u]) {
            if (!visited[v] && AM[u][v] == 2) {
                AM[u][v] = AM[v][u] = 1;
                p[v] = u;
                dfs(v);
                if (!found_way) AM[u][v] = AM[v][u] = 2;
                else break;
            }
        }

        for (auto&& v : AL[u]) {
            if (!visited[v] && AM[u][v] == 1) {
                AM[u][v] = AM[v][u] = 2;
                p[v] = u;
                dfs(v);
                if (!found_way) AM[u][v] = AM[v][u] = 1;
                else break;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> indegree(n, 0);
    AL.resize(n);
    vector<ii> queries;
    while (m--) {
        int u, v;
        cin >> u >> v; --u; --v;
        AL[u].push_back(v); 
        AL[v].push_back(u); 
    }

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v; --u; --v;
        queries.push_back({u, v});
        indegree[v]++;
        indegree[u]++;
    }

    int odd = 0;
    for (int i = 0; i < n; i++)
        if (indegree[i] % 2 == 1) ++odd;

    if (odd == 0) {
        cout << "YES\n";

        AM.assign(n, vector<int>(n, 0));
        for (int u = 0; u < n; u++) 
            for (auto&& v : AL[u]) AM[u][v] = AM[v][u] = 1;

        for (auto&& qr : queries) {
            src = qr.first, dst = qr.second;
            visited.assign(n, false);
            p.assign(n, -1);
            found_way = false;

            dfs(src);

            vector<int> path;
            while (dst != src) {
                path.push_back(dst);
                dst = p[dst];
            }
            path.push_back(src);

            cout << path.size() << endl;
            for (int i = path.size() - 1; i >= 0; i--) 
                cout << path[i] + 1 << " ";
            cout << endl;
        }
    } else {
        cout << "NO\n";
        cout << odd/2 << endl;
    }
}