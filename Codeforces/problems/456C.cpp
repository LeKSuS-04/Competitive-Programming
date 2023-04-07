/* 456C. Boredom */
// https://codeforces.com/problemset/problem/456/C
// Date: Oct/05/22 17:31
// Run time: 140 ms
// Memory: 2700 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& ai : a) cin >> ai;

    vector<vector<long long>> dp(2LL, vector<long long>(MAX, 0LL));
    vector<long long> count(MAX, 0LL);

    for (auto&& ai : a)
        count[ai]++;

    dp[1][1] = count[1];
    for (int i = 2; i < MAX; i++) {
        dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
        dp[1][i] = max(dp[0][i-2], dp[1][i-2]) + i*count[i];
    }

    cout << max(dp[0][MAX-1], dp[1][MAX-1]) << endl;
}