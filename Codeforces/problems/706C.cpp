/* 706C. Hard problem */
// https://codeforces.com/problemset/problem/706/C
// Date:
// Run time:
// Memory:
// Verdict:

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1 << 62;

bool is_smaller(const string& a, const string& b) {
    for (int i = 0; i < min(a.size(), b.size()); i++) {
        if (a[i] != b[i]) return a[i] < b[i];
    }
    return a.size() < b.size();
}

bool is_reversed_smaller(const string& a, const string& b) {
    for (int i = 0; i < min(a.size(), b.size()); i++) {
        if (a[a.size() - i - 1] != b[i]) return a[a.size() - i - 1] < b[i];
    }
    return a.size() < b.size();
}

int main() {
    int n;
    cin >> n;
    vector<ll> c(n);
    for (auto&& ci : c) cin >> ci;
    vector<string> s(n);
    for (auto&& si : s) cin >> si;

    vector<vector<ll>> dp(2, vector<ll>(n, INF));
    dp[1][0] = c[0];

    for (int i = 1; i < n; i++) {
        if (is_smaller(s[i], s[i-1]) && is_reversed_smaller(s[i], s[i-1])) {
            dp[0][i] = min(dp[0][i-1], dp[1][i-1]);
            dp[1][i] = ;
        }
    }

    cout << min(dp[0][n-1], dp[1][n-1]) << endl;
}