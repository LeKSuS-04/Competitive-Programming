/* UVa 11396 - Claw Decomposition */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=669&page=show_problem&problem=2391
// Date: 2021-08-22 12:31:33
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int UNVISITED = 0;
const int A = 1;
const int B = 2;

int main() {
    int n;
    while (cin >> n, n) {
        bool is_bipartite = true;
        vector<int> color(n, UNVISITED);
        vector<vector<int>> AL(n, vector<int>());

        int u, v;
        while (cin >> u >> v, u | v) {
            AL[u - 1].push_back(v - 1);
            AL[v - 1].push_back(u - 1);
        }

        queue<int> q;
        q.push(0); color[0] = A;
        while (!q.empty() && is_bipartite) {
            v = q.front(); q.pop();
            for (auto&& u : AL[v]) {
                if (color[u] == UNVISITED) {
                    color[u] = (color[v] == A ? B : A);
                    q.push(u);
                } else if (color[u] == color[v]) {
                    is_bipartite = false;
                    break;
                }
            }
        }

        if (is_bipartite) cout << "YES\n";
        else cout << "NO\n";
    }
}