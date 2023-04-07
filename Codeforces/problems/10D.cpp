#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif

    int n, m;
    cin >> n;
    vector<int> a(n);
    for (auto&& ai : a) cin >> ai;
    cin >> m;
    vector<int> b(m);
    for (auto&& bi : b) cin >> bi;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[n][m] << endl;
    int i = n, j = m;
    while (i != 0 && j != 0) {
        while (dp[i][j-1] == dp[i][j]) --j;
        if (i != n) cout << b[j] << ' ';
        --j;
        --i;
    }
    cout << b[j] << ' ';

    cout << endl;
}