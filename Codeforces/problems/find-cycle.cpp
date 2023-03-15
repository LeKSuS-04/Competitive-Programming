/* B. Поиск цикла */
// Date: 2023-03-15 14:25:08
// Run time: 560 ms
// Memory: 31900 KB
// Verdict: AC
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AL;
vector<bool> visited;
vector<int> path;
unordered_set<int> behind;
bool printed_answer = false;

void dfs(int u) {
    visited[u] = true;
    behind.insert(u);
    path.push_back(u);

    for (auto&& v : AL[u]) {
        if (!visited[v]) {
            dfs(v);
        } else {
            if (behind.find(v) != behind.end() && !printed_answer) {
                cout << "YES\n";
                vector<int> cycle;
                cycle.push_back(v + 1);
                for (auto it = path.rbegin(); *it != v; it++) {
                    cycle.push_back(*it + 1);
                }
                for (auto it = cycle.rbegin(); it != cycle.rend(); it++) {
                    cout << *it << ' ';
                }
                cout << endl;
                printed_answer = true;
            }
        }
    }

    path.pop_back();
    behind.erase(u);
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#else
    freopen("cycle2.in", "r", stdin);
    freopen("cycle2.out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    AL.resize(n);
    visited.assign(n, false);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        AL[u].push_back(v);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i);
    }

    if (!printed_answer) cout << "NO" << endl;
}