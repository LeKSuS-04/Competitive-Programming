/* D - M<=ab */
// https://atcoder.jp/contests/abc296/tasks/abc296_d
// Date: 2023-04-01 15:39:50
// Run time: 3632 KB
// Memory: 18 ms
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif
    ll n, m;
    cin >> n >> m;

    ll p = LONG_LONG_MAX;
    for (ll k = 1; k <= min(1'000'000LL, n); k++) {
        ll t = m / k + (m % k != 0);
        if (t <= n) {
            p = min(t * k, p);
        }
    }

    if (p == LONG_LONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << p << endl;
    }
    return 0;
}