/* UVa 1056 - Degrees of Separation */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3497
// Date: 2021-09-04 06:45:33
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
    int p, r, case_n = 0;
    while (cin >> p >> r, p | r) {
        string u, v;

        vector<vector<int>> AM(p, vector<int>(p, INF));
        unordered_map<string, int> mapper;
        unordered_map<int, string> rev_mapper;

        while (r--) {
            cin >> u >> v;

            if (mapper.find(u) == mapper.end()) {
                mapper[u] = mapper.size();
                rev_mapper[rev_mapper.size()] = u;
            }
            if (mapper.find(v) == mapper.end()) {
                mapper[v] = mapper.size();
                rev_mapper[rev_mapper.size()] = v;
            }

            AM[mapper[u]][mapper[v]] = AM[mapper[v]][mapper[u]] = 1;
        }
        for (int i = 0; i < p; i++) AM[i][i] = 0;
        for (int k = 0; k < p; k++)
            for (int i = 0; i < p; i++)
                for (int j = 0; j < p; j++) 
                    AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);

        int d = 0;
        for (int i = 0; i < p; i++)
            for (int j = 0; j < p; j++) 
                d = max(d, AM[i][j]);

        cout << "Network " << ++case_n << ": ";
        if (d == INF) cout << "DISCONNECTED\n\n";
        else cout << d << "\n\n";
    }
}