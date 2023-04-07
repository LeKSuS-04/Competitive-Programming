/* UVa 280 - Vertex */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=216
// Date: 2021-08-08 10:16:09
// Run time: 0.160
// Verdict: AC

#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

bitset<110> used;
vector<vector<int>> g;

void dfs(int v) {
    for (int i = 0; i < g[v].size(); i++) 
        if (!used[g[v][i]]) {
            used[g[v][i]] = 1;
            dfs(g[v][i]);
        }
}


int main() {
    int n, vi, vj, k, t, c;
    while (cin >> n, n) {
        g.assign(n + 1, vector<int>());

        while(cin >> vi, vi) {
            while(cin >> vj, vj) {
                g[vi].push_back(vj);
            }
        }

        cin >> k;
        while(k--) {
            cin >> t;
            used.reset();
            dfs(t);

            c = 0;
            for (int i = 1; i <= n; i++) if (!used[i]) c++;
            cout << c;
            for (int i = 1; i <= n; i++) if(!used[i]) cout << " " << i;
            cout << "\n";
        }
    }
}