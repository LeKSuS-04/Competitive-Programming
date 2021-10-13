/* UVa 11838 - Come and Go */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2938
// Date: 2021-08-25 10:05:31
// Runtime: 0.050
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

int UNVISITED = -1;

int dfs_count, SCC;
vector<vector<int>> AL;
vector<int> dfs_num, dfs_low, dfs_stack;
vector<bool> dfs_on_stack;

void count_scc(int u) {
    dfs_low[u] = dfs_num[u] = dfs_count++;
    dfs_stack.push_back(u);
    dfs_on_stack[u] = true;

    for (auto&& v : AL[u]) {
        if (dfs_num[v] == UNVISITED) count_scc(v);
        if (dfs_on_stack[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if (dfs_num[u] == dfs_low[u]) {
        while (true) {
            int v = dfs_stack.back(); 
            dfs_stack.pop_back(), dfs_on_stack[v] = false;
            if (u == v) break;
        }
        SCC++;
    }
}

int main() {
    int n, m;
    while (cin >> n >> m, n | m) {
        AL.assign(n, vector<int>());
        dfs_num.assign(n, UNVISITED);
        dfs_low.assign(n, 0);
        dfs_on_stack.assign(n, false);
        dfs_count = SCC = 0;

        int u, v, p;
        while (m--) {
            cin >> u >> v >> p;
            AL[u - 1].push_back(v - 1);
            if (p == 2) AL[v - 1].push_back(u - 1);
        }

        for (int i = 0; i < AL.size(); i++)
            if (dfs_num[i] == UNVISITED) {
                count_scc(i);
            }

        cout << (SCC == 1 ? 1 : 0) << endl;
    }
}