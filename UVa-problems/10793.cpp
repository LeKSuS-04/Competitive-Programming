/* UVa 10793 - The Orc Attack */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1734
// Date: 2021-09-09 15:55:59
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
    int TC, case_n = 0;
    cin >> TC;
    while (TC--) {
        int l, d;
        cin >> l >> d;

        vector<vector<int>> AM(l, vector<int>(l, INF));
        while (d--) {
            int u, v, w;
            cin >> u >> v >> w; --u; --v;
            AM[u][v] = min(AM[u][v], w);
            AM[v][u] = min(AM[v][u], w);
        }

        for (int i = 0; i < l; i++) AM[i][i] = 0;
        for (int k = 0; k < l; k++)
            for (int u = 0; u < l; u++)
                for (int v = 0; v < l; v++)
                    AM[u][v] = min(AM[u][v], AM[u][k] + AM[k][v]);

        int min_dist = INF;
        for (int v = 5; v < l; v++) {
            bool same_shortest = true;
            for (int u = 1; u < 5; u++) 
                if (AM[u][v] != AM[u - 1][v]) same_shortest = false;

            if (same_shortest) {
                int max_dist = -1;
                for (int u = 0; u < l; u++) 
                    max_dist = max(max_dist, AM[v][u]);

                min_dist = min(min_dist, max_dist);
            }
        }

        cout << "Map " << ++case_n << ": ";
        if (min_dist == INF) cout << "-1\n";
        else cout << min_dist << endl;
    }
}