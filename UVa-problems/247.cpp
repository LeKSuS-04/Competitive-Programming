/* UVa 247 - Calling Circles */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=183
// Date: 2021-08-25 12:18:37
// Runtime: 0.010
// Verdict: AC

#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

const int UNVISITED = -1;

int dfs_count;
vector<set<int>> AL, SCCs;
vector<int> dfs_low, dfs_num, dfs_stack;
vector<bool> dfs_on_stack;

void tarjan_SCC(int u) {
    dfs_num[u] = dfs_low[u] = dfs_count++;
    dfs_stack.push_back(u);
    dfs_on_stack[u] = true;

    for (auto&& v : AL[u]) {
        if (dfs_num[v] == UNVISITED) tarjan_SCC(v);
        if (dfs_on_stack[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if (dfs_num[u] == dfs_low[u]) {
        SCCs.push_back(set<int>());
        while (true) {
            int v = dfs_stack.back();
            dfs_stack.pop_back(), dfs_on_stack[v] = false;
            SCCs.back().insert(v);
            if (u == v) break;
        }
    }
}

int main() {
    int n, m, case_n = 0;
    while (cin >> n >> m, n | m) {
        dfs_count = 0;
        AL.assign(n, set<int>());
        SCCs.clear();
        dfs_low.assign(n, 0);
        dfs_num.assign(n, UNVISITED);
        dfs_stack.clear();
        dfs_on_stack.assign(n, false);

        unordered_map<string, int> mapper;
        unordered_map<int, string> rev_mapper;

        string u, v;
        int idx = 0;
        while (m--) {
            cin >> u >> v;
            if (mapper.find(u) == mapper.end())
                mapper[u] = idx, rev_mapper[idx] = u, ++idx;
            if (mapper.find(v) == mapper.end())
                mapper[v] = idx, rev_mapper[idx] = v, ++idx;

            AL[mapper[u]].insert(mapper[v]);
        }

        for (int i = 0; i < AL.size(); i++)
            if (dfs_num[i] == UNVISITED) tarjan_SCC(i);

        if (case_n != 0) cout << endl;
        printf("Calling circles for data set %d:\n", ++case_n);
        for (int i = 0; i < SCCs.size(); i++) {
            for (auto&& v : SCCs[i]) {
                if (v != *SCCs[i].begin()) cout << ", ";
                cout << rev_mapper[v];
            }
            cout << endl;
        }
    }
}