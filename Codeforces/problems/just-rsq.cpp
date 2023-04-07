/* A - Просто RSQ */
// https://codeforces.com/gym/100246/problem/A
// Date: 2023-02-25 13:22:01
// Run time: 1278 ms
// Memory: 2348 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class FenwickTree {
   public:
    FenwickTree(ll size) : ft(size + 1, 0) {}
    FenwickTree(const vector<ll> arr) : FenwickTree(arr.size()) {
        for (ll i = 1; i <= arr.size(); i++) {
            add(i, arr[i - 1]);
        }
    }

    ll sum(ll to) {
        ll answ = 0;
        for (; to != 0; to ^= to & -to) {
            answ += ft[to];
        }
        return answ;
    }
    ll sum(ll from, ll to) { return sum(to) - sum(from - 1); }

    void add(ll i, ll value) {
        for (; i < ft.size(); i += i & -i) {
            ft[i] += value;
        }
    }

   private:
    vector<ll> ft;
};

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#else
    freopen("rsq.in", "r", stdin);
    freopen("rsq.out", "w", stdout);
#endif

    ll n, q;
    cin >> n >> q;
    vector<ll> as(n);
    for (auto&& ai : as) cin >> ai;

    FenwickTree tree(as);

    while (q--) {
        ll cmd, x, y;
        cin >> cmd >> x >> y;
        if (cmd == 0) {
            cout << tree.sum(x, y) << endl;
        } else {
            ll d = y - as[x - 1];
            as[x - 1] = y;
            tree.add(x, d);
        }
    }
}