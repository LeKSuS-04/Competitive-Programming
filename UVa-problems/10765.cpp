/* UVa 10765 - Doves and bombs */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1706
// Date: 2021-08-23 07:34:55
// Runtime: 0.010
// Verdict: AC

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int UNVISITED = -1;

int dfs_counter, dfs_root, root_children;
vector<vector<int>> AL;
vector<int> dfs_low, dfs_num, dfs_parent, articulation_point;

void find_articulation_points(int u) {
    dfs_num[u] = dfs_low[u] = ++dfs_counter;
    for (auto&& v : AL[u]) {
        if (dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;
            if (u == dfs_root) root_children++;

            find_articulation_points(v);

            if (dfs_low[v] >= dfs_num[u]) {
                articulation_point[u]++;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
    int n, m;
    while (cin >> n >> m, n | m) {
        AL.assign(n, vector<int>());
        dfs_parent.assign(n, 0);
        dfs_low.assign(n, 0);
        dfs_num.assign(n, UNVISITED);
        articulation_point.assign(n, 1);

        int x, y;
        while (cin >> x >> y, x != -1 && y != -1) {
            AL[x].push_back(y);
            AL[y].push_back(x);
        }

        dfs_root = root_children = dfs_counter = 0;
        find_articulation_points(dfs_root);
        articulation_point[dfs_root] = root_children;

        vector<pair<int, int>> pigeon_values(n);
        for (int i = 0; i < articulation_point.size(); i++) {
            pigeon_values[i] = {i, articulation_point[i]};
        }
        sort(pigeon_values.begin(), pigeon_values.end(), 
            [](pair<int, int> a, pair<int, int> b) {
                if (a.second != b.second) return a.second > b.second;
                else return a.first < b.first;
            });

        for (int i = 0; i < m; i++) {
            cout << pigeon_values[i].first << " " << pigeon_values[i].second << endl;
        }
        cout << endl;
    }
}