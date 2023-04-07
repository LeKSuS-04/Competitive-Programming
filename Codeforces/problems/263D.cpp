/* 263D. Cycle in Graph */
// https://codeforces.com/problemset/problem/263/D
// Date: 2023-03-15 12:31:30
// Run time: 530 ms
// Memory: 10500 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<vector<int>> AL;
vector<bool> visited;
vector<int> path;
bool answer_printed = false;

void dfs(int u) {
    path.push_back(u);
    visited[u] = true;

    for (auto&& v : AL[u]) {
        if (!visited[v]) {
            dfs(v);
        } else {
            if (v == path[0] && path.size() > k && !answer_printed) {
                cout << path.size() << '\n';
                for (auto&& p : path) {
                    cout << p + 1 << ' ';
                }
                cout << endl;
                answer_printed = true;
            }
        }
    }
    path.pop_back();
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif

    cin >> n >> m >> k;

    AL.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        AL[u].push_back(v);
        AL[v].push_back(u);
    }

    srand(time(NULL));
    visited.assign(n, false);
    dfs(rand() % n);
}