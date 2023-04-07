/* 1808B. Playing in a Casino */
// https://codeforces.com/contest/1808/problem/B
// Date: 2023-04-03 22:07:54
// Run time: 436 ms
// Memory: 11772 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll tc;
    cin >> tc;
    while (tc--) {
        ll n, m;
        cin >> n >> m;

        vector<vector<ll>> cards(m, vector<ll>(n));
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                cin >> cards[j][i];
            }
        }

        ll res = 0;
        for (auto& row : cards) {
            sort(row.begin(), row.end());
            ll c = row.size();
            for (ll i = 1; i < row.size(); i++) {
                res += (row[i] - row[i - 1]) * (c - i) * i;
            }
        }
        cout << res << '\n';
    }
    cout.flush();
}