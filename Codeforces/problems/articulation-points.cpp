/* D. Точки сочленения */
// Date: 2023-03-15 14:58:57
// Run time: 996 ms
// Memory: 6700 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AL;
vector<int> dfs_low, dfs_num, dfs_parent;
int dfs_count = 0, dfs_root, root_children;
vector<bool> is_articulation_point;

void find_articulation_points(int u) {
    dfs_num[u] = dfs_low[u] = dfs_count++;
    for (auto&& v : AL[u]) {
        if (dfs_num[v] == -1) {
            dfs_parent[v] = u;
            if (u == dfs_root) ++root_children;

            find_articulation_points(v);

            if (dfs_low[v] >= dfs_num[u]) {
                is_articulation_point[u] = true;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (dfs_parent[u] != v) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#else
    freopen("points.in", "r", stdin);
    freopen("points.out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    AL.resize(n);
    dfs_low.resize(n);
    dfs_parent.resize(n);
    dfs_num.assign(n, -1);
    is_articulation_point.assign(n, false);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        AL[u].push_back(v);
        AL[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (dfs_num[i] == -1) {
            dfs_root = i;
            root_children = 0;
            find_articulation_points(i);
            is_articulation_point[dfs_root] = (root_children > 1);
        }
    }

    vector<int> articulation_points;
    for (int i = 0; i < n; i++) {
        if (is_articulation_point[i]) articulation_points.push_back(i);
    }

    cout << articulation_points.size() << '\n';
    for (int i = 0; i < articulation_points.size(); i++) {
        cout << articulation_points[i] + 1 << ' ';
    }
    cout << endl;
}