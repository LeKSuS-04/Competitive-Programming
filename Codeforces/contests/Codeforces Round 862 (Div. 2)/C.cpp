/* 1805C. Place for a Selfie */
// https://codeforces.com/contest/1805/problem/C
// Date: 2023-04-02 19:09:57
// Run time: 1965 ms
// Memory: 2064 KB
// Verdict: AC

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll n, m;
vector<ll> ks;
ld a, b, c;
const ld e = 0;

bool intercepts(ll k) { return (pow(b - k, 2) - 4.0 * a * c) >= e; }

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        ks.clear();
        for (int i = 0; i < n; i++) {
            ld k;
            cin >> k;
            ks.push_back(k);
        }

        sort(ks.begin(), ks.end());

        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;

            if (c * a < 0) {
                cout << "NO" << endl;
                continue;
            }
            ld x1 = sqrtl(c / a), x2 = -sqrtl(c / a);
            ld k1 = 2 * a * x1 + b;
            ld k2 = 2 * a * x2 + b;

            auto check = [&](ld k) {
                auto sml = lower_bound(ks.begin(), ks.end(), k);
                auto big = upper_bound(ks.begin(), ks.end(), k);
                if (big != ks.end() && !intercepts(*big)) {
                    return make_pair(true, *big);
                }
                if (sml != ks.begin() && !intercepts(*prev(sml))) {
                    return make_pair(true, *prev(sml));
                }
                return make_pair(false, 0LL);
            };

            bool found = false;
            for (auto k : {k1, k2}) {
                pair<bool, int> c = check(k);
                if (c.first) {
                    cout << "YES\n" << c.second << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "NO" << endl;
            }
        }
        cout << endl;
    }
}