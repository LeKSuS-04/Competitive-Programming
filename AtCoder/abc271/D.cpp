/* D - Flip and Adjust */
// https://atcoder.jp/contests/abc271/tasks/abc271_d
// Date: 2022-10-01 16:21:18
// Run time: 9 ms
// Memory: 4684 KB	
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 110;
const int MAX_S = 10010;
char memo[MAX_N][MAX_S];

int main() {
    int n, s;
    cin >> n >> s;

    memset(memo, 0, sizeof memo);

    memo[0][0] = 1;

    vector<pair<int, int>> ab(n);
    for (auto&& abi : ab) cin >> abi.first >> abi.second;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (j >= ab[i-1].first) memo[i][j] |= memo[i - 1][j - ab[i-1].first];
            if (j >= ab[i-1].second) memo[i][j] |= memo[i - 1][j - ab[i-1].second];
        }
    }

    if (memo[n][s]) {
        cout << "Yes\n";
        vector<char> path;
        for (int i = n; i > 0; i--) {
            pair<int, int> coin = ab[i-1];
            int h = coin.first;
            int t = coin.second;

            if (s - t >= 0 && memo[i-1][s-t]) {
                path.push_back('T');
                s -= t;
            } else {
                path.push_back('H');
                s -= h;
            }
        }
        for (int i = n; i > 0; i--) {
            cout << path[i-1];
        }
        cout << endl;
    } else {
        cout << "No\n";
    }
}