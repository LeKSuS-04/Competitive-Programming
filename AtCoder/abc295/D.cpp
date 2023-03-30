/* D - Three Days Ago */
// https://atcoder.jp/contests/abc295/tasks/abc295_d
// Date: 2023-03-25 15:25:27
// Run time: 104 ms
// Memory: 62528 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll compress(const vector<ll>& a) {
    ll r = 0;
    for (ll i = 0; i < 10; i++) {
        r |= (a[i] % 2) << i;
    }
    return r;
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif
    string s;
    cin >> s;

    deque<vector<ll>> d(s.size(), vector<ll>(10, 0));
    for (ll i = 0; i < s.size(); i++) {
        if (i != 0) {
            for (int j = 0; j < d[i].size(); j++) {
                d[i][j] += d[i-1][j];
            }
        }
        d[i][s[i] - '0']++;
    }
    d.push_front(vector<ll>(10, 0));

    vector<ll> count(1 << 10, 0);
    for (ll i = 0; i < d.size(); i++) {
        count[compress(d[i])]++;
    }

    ll answ = 0;
    for (ll i = 0; i < count.size(); i++) {
        answ += count[i] * (count[i] - 1) / 2;
    }
    cout << answ << endl;
}