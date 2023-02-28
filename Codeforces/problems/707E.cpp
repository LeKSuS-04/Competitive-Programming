/* 707E. Garlands */
// https://codeforces.com/problemset/problem/707/e
// Date: 2023-02-27 20:13:04
// Run time: 77400 KB
// Memory: 1014 ms
// Verdict: AC

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAX_LIGHTS = 2000 + 10;

struct Lamp {
    ll x, y, w;
};

class FenwickTree2D {
   public:
    FenwickTree2D(ll n, ll m) : ft(n + 1, vector<ll>(m + 1, 0)) {}

    ll lsb(ll n) { return n & -n; }

    ll sum(ll x, ll y) {
        ll r = 0;
        for (ll i = x; i > 0; i ^= lsb(i)) {
            for (ll j = y; j > 0; j ^= lsb(j)) {
                r += ft[i][j];
            }
        }
        return r;
    }

    ll sum(ll x1, ll y1, ll x2, ll y2) {
        return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1);
    }

    void add(ll x, ll y, ll v) {
        for (ll i = x; i < ft.size(); i += lsb(i)) {
            for (ll j = y; j < ft[x].size(); j += lsb(j)) {
                ft[i][j] += v;
            }
        }
    }

   private:
    vector<vector<ll>> ft;
};

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<Lamp>> lights(k, vector<Lamp>(0));
    bitset<MAX_LIGHTS> is_turned_on, changed;
    FenwickTree2D ftree(n, m);
    is_turned_on.set();
    changed.reset();
    for (ll i = 0; i < k; i++) {
        ll len;
        cin >> len;
        lights[i].resize(len);
        for (auto&& lamp : lights[i]) {
            cin >> lamp.x >> lamp.y >> lamp.w;
            ftree.add(lamp.x, lamp.y, lamp.w);
        }
    }

    ll q;
    cin >> q;
    while (q--) {
        string cmd;
        cin >> cmd;
        if (cmd == "ASK") {
            for (ll i = 0; i < k; i++) {
                if (changed[i]) {
                    for (auto&& lamp : lights[i]) {
                        if (is_turned_on[i]) {
                            ftree.add(lamp.x, lamp.y, lamp.w);
                        } else {
                            ftree.add(lamp.x, lamp.y, -lamp.w);
                        }
                    }
                    changed[i] = false;
                }
            }

            ll x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << ftree.sum(x1, y1, x2, y2) << '\n';
        } else {
            ll i;
            cin >> i;
            is_turned_on[i - 1].flip();
            changed[i - 1].flip();
        }
    }
}