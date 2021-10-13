/* UVa 11080 - Place the Guards */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=669&page=show_problem&problem=2021
// Date: 2021-08-22 12:14:14
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int UNVISITED = 0;
const int A = 1;
const int B = 2;

int guards;
bool is_bipartite;
vector<int> color;
vector<vector<int>> AL;

void check_bipartite(int v) {
    int a = 1, b = 0;
    queue<int> q; q.push(v);
    color[v] = A;

    while (!q.empty() && is_bipartite) {
        int u = q.front(); q.pop();

        for (auto&& v : AL[u]) {
            if (color[v] == UNVISITED) {
                if (color[u] == A) color[v] = B, ++b;
                if (color[u] == B) color[v] = A, ++a;
                q.push(v);
            } else if (color[v] == color[u]) {
                is_bipartite = false;
                break;
            }
        }
    }

    guards += max(1, min(a, b));
}


int main() {    
    int TC;
    cin >> TC;
    while (TC--) {
        int n, m, v, u;
        cin >> n >> m;
        
        guards = 0;
        is_bipartite = true;
        color.assign(n, UNVISITED);
        AL.assign(n, vector<int>());

        while (m--) {
            cin >> u >> v;
            AL[u].push_back(v);
            AL[v].push_back(u);
        }

        for (int i = 0; i < n && is_bipartite; i++) {
            if (color[i] == UNVISITED) {
                check_bipartite(i);
            }
        }

        if (is_bipartite) cout << guards << endl;
        else cout << -1 << endl;
    }
}