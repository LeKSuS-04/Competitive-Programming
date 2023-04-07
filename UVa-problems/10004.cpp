/* UVa 10004 - Bicoloring */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=945
// Date: 2021-08-22 11:23:57
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

        int m, u, v;
        cin >> m;
        while (m--) {
            cin >> u >> v;
            AL[u].push_back(v);
            AL[v].push_back(u);
        }

        queue<int> q;
        q.push(0); color[0] = A;
        while (!q.empty() && is_bipartite) {
            v = q.front(); q.pop();

            for (auto&& u : AL[v]) {
                if (color[u] == UNVISITED) {
                    color[u] = (color[v] == A ? B : A);
                    q.push(u);
                } else if (color[v] == color[u]) {
                    is_bipartite = false;
                    break;
                }
            }
        }

        if (is_bipartite) cout << "BICOLORABLE.\n";
        else              cout << "NOT BICOLORABLE.\n";
    }
}