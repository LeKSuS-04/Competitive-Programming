/* 436B. Art Union */
// https://codeforces.com/problemset/problem/416/B
// Date: ?
// Run time: 296 ms
// Memory: 5500 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> t(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> t[i][j];
        }
    }

    vector<vector<int>> memo(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) memo[i][j] = t[i][j];
            else if (i == 0) memo[i][j] = t[i][j] + memo[i][j-1];
            else if (j == 0) memo[i][j] = t[i][j] + memo[i-1][j];
            else memo[i][j] = max(memo[i-1][j], memo[i][j-1]) + t[i][j]; 
        }
    }

    for (int i = 0; i < m; i++) {
        cout << memo[i][n-1] << " ";
    }
    cout << endl;
}