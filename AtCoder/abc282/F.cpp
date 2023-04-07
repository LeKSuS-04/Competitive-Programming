/* F - Union of Two Sets */
// https://atcoder.jp/contests/abc282/tasks/abc282_f
// Date: 2022-12-17 16:04:24
// Run time: 893 ms	
// Memory: 11396 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

ll dohash(ii p) { return ((ll)p.first) * 100000 + p.second; }
ii unhash(ll p) { return {p / 100000, p % 100000}; }

int main() {
    int n;
    cin >> n;

    unordered_map<ll, int> mapping;
    unordered_map<int, ll> unmapping;
    int m = 0;
    auto add_pair = [&](int a, int b) {
        ++m;
        mapping[dohash({a,b})] = m;
        mapping[dohash({b,a})] = m;
        unmapping[m] = dohash({a, b});
    };

    for (int i = 0; i < n; i++) {
        add_pair(i + 1, i + 1);
    }
    for (int exp = 0; (1 << exp) <= n; exp++) {
        for (int i = 0; i + (1 << exp) < n; i++) {
            int a = i + 1;
            int b = i + (1 << exp) + 1;
            add_pair(a, b);
        }
    }
    cout << m << endl;

    for (int i = 1; i <= m; i++) {
        auto u = unhash(unmapping[i]);
        cout << u.first << ' ' << u.second << endl;
    }

    int q;
    cin >> q;
    while (q--) {
        ll a, b;
        cin >> a >> b;
    
        if (a == b) {
            cout << a << ' ' << a << endl;
        } else {
            ll max_exp = 1;
            while (max_exp*2 < (b - a)) max_exp *= 2;
            cout << mapping[dohash({a,a+max_exp})] << ' ' << mapping[dohash({b-max_exp,b})] << endl;
        }
    }
    return 0;
}