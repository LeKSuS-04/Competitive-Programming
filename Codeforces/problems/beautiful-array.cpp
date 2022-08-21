/* 1715B - Beautiful Array */
// https://codeforces.com/contest/1715/problem/B
// Date: Aug/21/2022 22:14
// Run time: 46 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int TC; cin >> TC;
    while (TC--) {
        ll n, k, b, s;
        cin >> n >> k >> b >> s;

        if (s < k*b || k*b + n*(k-1) < s) cout << "-1\n";
        else {
            ll l = s - k*b, d;
            for (int i = 0; i < n; i++) {
                d = min(l, k - 1);
                l -= d;
                if (i == 0) d += k*b;
                cout << d << ' ';
            }
            cout << '\n';
        }
    }
} 