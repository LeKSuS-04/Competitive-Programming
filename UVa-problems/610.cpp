/* UVa 610 - Street Directions */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=670&page=show_problem&problem=551
// Date: 2021-08-23 11:04:22
// Runtime: 0.060
// Verdict: AC

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int UNVISITED = -1;

int dfs_count;
vector<vector<int>> AL;
vector<int> dfs_low, dfs_num, dfs_parent;
vector<pair<int, int>> streets;

void find_articulation_bridges(int u) {
    dfs_low[u] = dfs_num[u] = dfs_count++;
    for (auto&& v : AL[u]) {
        if (dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;

            find_articulation_bridges(v);

            streets.push_back({u, v});
            if (dfs_low[v] > dfs_num[u]) {
                streets.push_back({v, u});
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u]) {
            if (dfs_num[v] < dfs_num[u]) streets.push_back({u, v});
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
    int n, m, u, v, case_n = 0;
    while (cin >> n >> m, n | m) {
        AL.assign(n, vector<int>());
        dfs_low.assign(n, 0);
        dfs_num.assign(n, UNVISITED);
        dfs_parent.assign(n, 0);
        streets.clear();

        while (m--) {
            cin >> u >> v;
            AL[u - 1].push_back(v - 1);
            AL[v - 1].push_back(u - 1);
        }

        dfs_count = 0;
        find_articulation_bridges(0);

        cout << ++case_n << "\n\n";
        for (auto&& s : streets) {
            cout << s.first + 1 << " " << s.second + 1 << endl;
        }
        cout << "#\n";
    }
}