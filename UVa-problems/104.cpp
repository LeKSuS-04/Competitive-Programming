/* UVa 104 - Arbitrage */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=40
// Date: 2021-09-04 10:15:27
// Runtime: 0.060
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<vector<vector<float>>> AM(n, vector<vector<float>>(n, vector<float>(n,  0)));
        vector<vector<vector<  int>>>  p(n, vector<vector<  int>>(n, vector<  int>(n, -1)));

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) {
                if (i == j) AM[0][i][j] = 1.0;
                else cin >> AM[0][i][j];
                p[0][i][j] = i;
            }

        for (int s = 1; s < n; s++) 
            for (int k = 0; k < n; k++)
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++) {
                        float res = AM[s - 1][i][k] * AM[0][k][j];
                        if (res > AM[s][i][j]) {
                            AM[s][i][j] = res;
                            p[s][i][j] = k;
                        }
                    }
        
        int s, from = -1;
        for (s = 1; s < n && from == -1; s++) 
            for (int i = 0; i < n && from == -1; i++) 
                if (AM[s][i][i] > 1.01) from = i;
        --s;

        if (from == -1) cout << "no arbitrage sequence exists\n";
        else {
            vector<int> out;

            int cur = from;
            for (int i = s; i > -1; i--) {
                cur = p[i][from][cur];
                out.push_back(cur + 1);
            }

            for (int i = out.size() - 1; i >= 0; i--) 
                cout << out[i] << " ";
            cout << from + 1 << endl;
        }
    }
}