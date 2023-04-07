/* UVa 10199 - Tourist Guide */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=670&page=show_problem&problem=1140
// Date: 2021-08-23 08:59:48
// Runtime: 0.000
// Verdict: AC

#include <algorithm>
#include <bitset>
#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>
using namespace std;

const int UNVISITED = -1;

int dfs_count, dfs_root, root_children;
vector<vector<int>> AL;
vector<int> dfs_low, dfs_num, dfs_parent;
bitset<110> articulation_point;

void find_articulation_points(int u) {
    dfs_num[u] = dfs_low[u] = dfs_count++;
    for (auto&& v : AL[u]) {
        if (dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;
            if (u == dfs_root) root_children++;

            find_articulation_points(v);

            if (dfs_low[v] >= dfs_num[u]) {
                articulation_point[u] = true;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
    int n, m, case_n;
    string u, v;
    while (cin >> n, n) {
        AL.assign(n, vector<int>());
        dfs_low.assign(n, 0);
        dfs_num.assign(n, UNVISITED);
        dfs_parent.assign(n, 0);
        articulation_point.reset();

        unordered_map<string, int> mapper;
        unordered_map<int, string> rev_mapper;

        for (int i = 0; i < n; i++) {
            cin >> u;
            mapper[u] = i;
            rev_mapper[i] = u;
        }

        cin >> m;
        while (m--) {
            cin >> u >> v;
            AL[mapper[u]].push_back(mapper[v]);
            AL[mapper[v]].push_back(mapper[u]);
        }

        for (int i = 0; i < n; i++) if (dfs_num[i] == UNVISITED) {
            dfs_root = i;
            dfs_count = root_children = 0;
            find_articulation_points(dfs_root);
            articulation_point[dfs_root] = (root_children > 1);
        }

        vector<string> cities;
        for (int i = 0; i < n; i++) if (articulation_point[i]) {
            cities.push_back(rev_mapper[i]);
        }

        if (case_n != 0) cout << endl;
        printf("City map #%d: %d camera(s) found\n", ++case_n, articulation_point.count());
        sort(cities.begin(), cities.end());
        for (auto&& c : cities) cout << c << endl;
    }
}