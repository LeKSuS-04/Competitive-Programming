/* UVa 12442 - Forwarding Emails */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3873
// Date: 2021-08-21 12:47:57
// Runtime: 0.280
// Verdict: AC

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

const int UNVISITED = 0;
const int EXPLORED = 1;
const int VISITED = 2;

int TC, n, u, v, res, mx, mxi, cntr = 0;
vector<int> used;
vector<int> g;

int dfs(int v) {
    used[v] = EXPLORED;

    int c = 1;
    if (used[g[v]] != EXPLORED) c = 1 + dfs(g[v]);
    
    used[v] = VISITED;
    return c;
}

int main() {
    cin >> TC;
    while (TC--) {
        cin >> n;
        g.assign(n, 0);
        used.assign(n, UNVISITED);
        while (n--) {
            cin >> u >> v;
            g[u - 1] = v - 1;
        }

        mx = mxi = 0;
        for (int i = 0; i < used.size(); i++) {
            if (used[i] == UNVISITED) {
                res = dfs(i);
                if (res > mx) mx = res, mxi = i;
            }
        }
        printf("Case %d: %d\n", ++cntr, mxi + 1);
    }
}