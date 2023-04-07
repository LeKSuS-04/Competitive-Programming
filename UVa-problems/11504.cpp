/* UVa 11504 - Dominos */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2499
// Date: 2021-08-25 13:01:46
// Runtime: 0.170
// Verdict: AC

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int UNVISITED = 0;
const int VISITED = 1;

vector<vector<int>> AL;
vector<int> dfs_num, sorted;

void toposort(int u) {
    dfs_num[u] = VISITED;
    for (auto&& v : AL[u])
        if (dfs_num[v] == UNVISITED) toposort(v);

    sorted.push_back(u);
}

void dfs(int u) {
    dfs_num[u] = VISITED;
    for (auto&& v : AL[u])
        if (dfs_num[v] == UNVISITED) dfs(v);
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, m, d = 0;
        cin >> n >> m;

        AL.assign(n, vector<int>());
        dfs_num.assign(n, UNVISITED);
        sorted.clear();

        int u, v;
        while (m--) {
            cin >> u >> v;
            AL[u - 1].push_back(v - 1);
        }

        for (int i = 0; i < AL.size(); i++)
            if (dfs_num[i] == UNVISITED) toposort(i);
        reverse(sorted.begin(), sorted.end());

        dfs_num.assign(n, UNVISITED);
        for (int i = 0; i < sorted.size(); i++) 
            if (dfs_num[sorted[i]] == UNVISITED) {
                dfs(sorted[i]);
                d++;
            }
        cout << d << endl;
    }
}