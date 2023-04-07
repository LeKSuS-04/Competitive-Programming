/* C. Мосты */
// Date: 2023-03-15 14:45:13
// Run time: 1872 ms
// Memory: 30600 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);

        if (h1 == h2) return h1;
        return h1 ^ h2;
    }
};

unordered_map<pair<int, int>, int, hash_pair> pair_to_index;

vector<vector<int>> AL;
vector<int> dfs_num, dfs_low, dfs_parent;
int dfs_counter = 0;
vector<pair<int, int>> bridges;

void find_articulation_bridges(int u) {
    dfs_num[u] = dfs_low[u] = dfs_counter++;
    for (auto&& v : AL[u]) {
        if (dfs_num[v] == -1) {
            dfs_parent[v] = u;
            find_articulation_bridges(v);

            if (dfs_low[v] > dfs_num[u]) {
                bridges.push_back({u, v});
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#else
    freopen("bridges.in", "r", stdin);
    freopen("bridges.out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    AL.resize(n);
    dfs_num.assign(n, -1);
    dfs_low.assign(n, -1);
    dfs_parent.assign(n, -1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        AL[u].push_back(v);
        AL[v].push_back(u);

        pair_to_index[{u, v}] = pair_to_index[{v, u}] = i;
    }

    for (int i = 0; i < n; i++) {
        if (dfs_num[i] == -1) {
            find_articulation_bridges(i);
        }
    }

    vector<int> bridge_indexes;
    for (auto&& bridge : bridges) {
        bridge_indexes.push_back(pair_to_index[bridge] + 1);
    }
    sort(bridge_indexes.begin(), bridge_indexes.end());

    cout << bridge_indexes.size() << '\n';
    for (auto&& i : bridge_indexes) {
        cout << i << ' ';
    }
    cout << endl;
}