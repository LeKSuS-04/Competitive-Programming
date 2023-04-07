/* 1706B. Making towers */
// https://codeforces.com/contest/1706/problem/B
// Date: Jul/25/2022 12:07
// Run time: 265 ms 
// Memory: 1700 KB 
// Verdict: AC

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        vector<vector<int>> m = {
            vector<int>(n, 0),
            vector<int>(n, 0)
        };

        int c;
        for (int i = 0; i < n; i++) {
            cin >> c; c--;
            m[i%2][c] = max(m[i%2][c], m[(i+1)%2][c] + 1);
        }

        for (int i = 0; i < n; i++) {
            cout << max(m[0][i], m[1][i]) << ' ';
        }
        cout << endl;
    }
}