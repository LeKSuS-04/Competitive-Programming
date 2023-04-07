/* G - Shopping in AtCoder store */
// https://atcoder.jp/contests/abc289/tasks/abc289_g
// Verdict: Not submitted

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
vector<ll> b;
vector<ll> c;


ll profit(ll price, ll item) {
    ll p = price - c[item];
    if (b.front() >= p) {
        return n * price;
    }
    if (b.back() < p) {
        return 0;
    }

    ll l = 0, r = n;
    while (r - l != 1) {
        ll k = (r + l) / 2;
        if (b[k] >= p) r = k;
        else l = k;
    }
    return (n - r) * price;
}

int main() {
    #ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
    #endif
    
    cin >> n >> m;
    b.resize(n);
    c.resize(m);
    for (auto&& bi : b) cin >> bi;
    for (auto&& ci : c) cin >> ci;
    
    sort(b.begin(), b.end());

    for (int i = 0; i < m; i++) {
        ll l = 0, r = INT_MAX / 2;
        while (r - l > 100) {
            ll d = (r - l) / 3;
            ll m1 = l + d;
            ll m2 = l + 2*d;
            if (profit(m2, i) > profit(m1, i)) {
                l = m1;
            } else {
                r = m2;
            }
        }

        ll m = 0;
        for (int j = l - 100; j <= r + 100; j++) {
            m = max(m, profit(j, i));
        }
        cout << m << ' ';
    }
    cout << endl;
}