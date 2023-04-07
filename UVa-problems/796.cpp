/* UVa 796 - Critical Links */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=737
// Date: 2021-08-23 09:25:51
// Runtime: 0.000
// Verdict: AC

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const int UNVISITED = -1;

int dfs_count;
vector<vector<int>> AL;
vector<int> dfs_num, dfs_low, dfs_parent;
vector<pair<int, int>> articulation_bridges;

void find_articulation_bridges(int u) {
    dfs_num[u] = dfs_low[u] = dfs_count++;
    for (auto&& v : AL[u]) {
        if (dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;

            find_articulation_bridges(v);

            if (dfs_low[v] > dfs_num[u]) {
                articulation_bridges.push_back({
                    min(v, u), max(v, u)
                });
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
    int n;
    while (cin >> n) {
        AL.assign(n, vector<int>());
        dfs_num.assign(n, UNVISITED);
        dfs_low.assign(n, 0);
        dfs_parent.assign(n, 0);
        articulation_bridges.clear();

        int u, v, m;
        string s;
        for (int i = 0; i < n; i++) {
            cin >> u >> s;
            m = stoi(s.substr(1, s.size() - 2));
            while (m--) {
                cin >> v;
                AL[u].push_back(v);
            }
        }

        for (int i = 0; i < n; i++) if(dfs_num[i] == UNVISITED) {
            dfs_count = 0;
            find_articulation_bridges(i);
        }

        sort(articulation_bridges.begin(), articulation_bridges.end());

        cout << articulation_bridges.size() << " critical links\n";
        for (auto&& b : articulation_bridges) {
            cout << b.first << " - " << b.second << endl;
        }
        cout << endl;
    }
}