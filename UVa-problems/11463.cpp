/* UVa 11463 - Commandos */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=682&page=show_problem&problem=2458
// Date: 2021-09-01 16:35:55
// Runtime: 0.020
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
    int TC, case_n = 0;
    cin >> TC;
    while (TC--) {
        int n, r, u, v, s, d;
        cin >> n >> r;

        vector<vector<int>> AM(n, vector<int>(n, INF));
        while (r--) {
            cin >> u >> v;
            AM[u][v] = AM[v][u] = 1;
        }
        cin >> s >> d;

        for (int i = 0; i < n; i++) AM[i][i] = 0;
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);

        int t = -1;
        for (int i = 0; i < n; i++)  
            t = max(t, AM[s][i] + AM[i][d]);

        cout << "Case " << ++case_n << ": " << t << endl;
    }
}