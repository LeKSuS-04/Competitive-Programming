/* E - Choose Two and Eat One */
// https://atcoder.jp/contests/abc282/tasks/abc282_e
// Not submimtted 

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

ll dohash(ii p) { return ((ll)p.first) * 100000 + p.second; }
ii unhash(ll p) { return {p / 100000, p % 100000}; }
ll m;

ll qpow(ll a, ll p) {
    if (p == 1) return a;
    if (p % 2 == 0) return qpow(a * a % m, p / 2);
    return a * qpow(a, p - 1) % m;
}

ll f(ll x, ll y) { return (qpow(x, y) + qpow(y, x)) % m; }

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif

    ll n;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto&& ai : a) {
        cin >> ai;
    }

    ll mx = -1;
    for (int i = 0; i < n; i++) {
        ll res = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                res = (res + f(a[i], a[j]));
            }
        }
    }
}