/* E - Transition Game */
// https://atcoder.jp/contests/abc296/tasks/abc296_e
// Date: 2023-04-01 16:25:40
// Run time: 150 ms
// Memory: 42136 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AL, sccs;
vector<int> dfs_num, dfs_low, dfs_stack, scc_num;
vector<bool> dfs_on_stack;
int dfs_count = 0;

void find_sccs(int u) {
    dfs_num[u] = dfs_low[u] = dfs_count++;
    dfs_stack.push_back(u);
    dfs_on_stack[u] = true;

    for (auto&& v : AL[u]) {
        if (dfs_num[v] == -1) find_sccs(v);
        if (dfs_on_stack[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if (dfs_low[u] == dfs_num[u]) {
        sccs.push_back(vector<int>());
        while (true) {
            int v = dfs_stack.back();
            dfs_stack.pop_back();
            dfs_on_stack[v] = false;
            sccs.back().push_back(v);
            scc_num[v] = sccs.size() - 1;
            if (u == v) break;
        }
    }
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    vector<int> a(n);
    AL.resize(n);

    dfs_num.assign(n, -1);
    dfs_low.assign(n, -1);
    scc_num.resize(n);
    dfs_on_stack.assign(n, false);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        AL.resize(n);
        --a[i];
        AL[i].push_back(a[i]);
    }

    for (int i = 0; i < n; i++) {
        if (dfs_num[i] == -1) {
            find_sccs(i);
        }
    }

    int c = 0;
    for (int i = 0; i < n; i++) {
        if (sccs[scc_num[i]].size() > 1 || a[i] == i) {
            ++c;
        }
    }
    cout << c << endl;
}