/* UVa 315 - Network */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=670&page=show_problem&problem=251
// Date: 2021-08-23 06:15:25
// Runtime: 0.000
// Verdict: AC

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

const int UNVISITED = -1;

int dfs_counter, dfs_root, root_children;
vector<vector<int>> AL;
vector<int> dfs_num, dfs_low, dfs_parent;
vector<bool> articulation_point;

void find_articulation_point(int u) {
    dfs_num[u] = dfs_low[u] = dfs_counter++;
    for (auto&& v : AL[u]) {
        if (dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;
            if (u == dfs_root) root_children++;

            find_articulation_point(v);

            if (dfs_low[v] >= dfs_num[u]) articulation_point[u] = true;
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
    int n, u, v;
    string s;
    while (cin >> n, n) {
        AL.assign(n, vector<int>());
        articulation_point.assign(n, false);
        dfs_num.assign(n, UNVISITED);
        dfs_low.assign(n, 0);
        dfs_parent.assign(n, 0);
        getline(cin, s);

        istringstream sin;
        while (getline(cin, s), s != "0") {
            sin = istringstream(s);
            sin >> u;
            while (sin >> v) {
                AL[u - 1].push_back(v - 1);
                AL[v - 1].push_back(u - 1);
            }
        }

        dfs_counter = 0, dfs_root = 0, root_children = 0;
        find_articulation_point(dfs_root);
        articulation_point[dfs_root] = (root_children > 1);
        cout << count(articulation_point.begin(), 
                      articulation_point.end(), 
                      true) << endl;
    }
}