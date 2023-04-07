/* A. Предок */
// Date: 2023-03-14 20:53:08
// Run time: 1122 ms
// Memory: 38100 KB
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

vector<pair<int, int>> queries;
vector<vector<int>> child_to_parent_queries;
unordered_map<pair<int, int>, bool, hash_pair> responces;
vector<vector<int>> AL;
vector<bool> visited;
unordered_set<int> passed;

void dfs(int u) {
    visited[u] = true;
    for (auto&& q_a : child_to_parent_queries[u]) {
        if (responces.find({q_a, u}) != responces.end()) {
            responces[{q_a, u}] = passed.find(q_a) != passed.end();
        }
    }
    passed.insert(u);

    for (auto&& v : AL[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }

    passed.erase(u);
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#else
    freopen("ancestor.in", "r", stdin);
    freopen("ancestor.out", "w", stdout);
#endif

    int n, m;
    cin >> n;

    AL.resize(n);
    visited.assign(n, false);
    vector<int> roots;
    for (int v = 0; v < n; v++) {
        int u;
        cin >> u;

        --u;
        if (u != -1) {
            AL[u].push_back(v);
        } else {
            roots.push_back(v);
        }
    }

    cin >> m;
    child_to_parent_queries.resize(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        child_to_parent_queries[b].push_back(a);
        queries.push_back({a, b});
        responces[{a, b}] = false;
    }

    vector<int> leaves;
    for (auto&& root : roots) {
        dfs(root);
    }

    for (auto&& [a, b] : queries) {
        cout << (responces[{a, b}] ? 1 : 0) << '\n';
    }
    cout.flush();
}