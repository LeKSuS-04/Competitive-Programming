#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class SegmentTree {
   public:
    SegmentTree(const vector<ll>& v) {
        values = {v.begin(), v.end()};
        s.resize(values.size() * 4);
        lazy.assign(values.size() * 4, 0);
        build(1, 0, values.size() - 1);
    }

    ll query(ll l, ll r) { return query(1, 0, values.size() - 1, l, r); }

    void update(ll l, ll r, ll value) { update(1, 0, values.size() - 1, l, r, value); }

   private:
    static const ll INVALID = 1'000'000'000;
    vector<ll> s, lazy, values;

    ll l(ll p) { return p << 1; }
    ll r(ll p) { return (p << 1) + 1; }

    void build(ll p, ll L, ll R) {
        if (L == R) {
            s[p] = values[L];
            return;
        }

        ll m = (R + L) / 2;
        build(l(p), L, m);
        build(r(p), m + 1, R);
        s[p] = min(s[l(p)], s[r(p)]);
    }

    void propagate(ll p, ll L, ll R) {
        s[p] += lazy[p];
        if (L != R) {
            lazy[l(p)] += lazy[p];
            lazy[r(p)] += lazy[p];
        }
        lazy[p] = 0;
    }

    ll query(ll p, ll L, ll R, ll ql, ll qr) {
        if (lazy[p] != 0) {
            propagate(p, L, R);
        }

        if (ql > R || qr < L) return INVALID;
        if (ql <= L && R <= qr) return s[p];

        ll m = (L + R) / 2;
        ll lsubtree = query(l(p), L, m, ql, min(qr, m));
        ll rsubtree = query(r(p), m + 1, R, max(ql, m + 1), qr);
        return min(lsubtree, rsubtree);
    }

    void update(ll p, ll L, ll R, ll ql, ll qr, ll value) {
        if (lazy[p] != 0) {
            propagate(p, L, R);
        }

        if (ql > R || qr < L) return;
        if (ql <= L && R <= qr) {
            s[p] += value;
            if (R != L) {
                lazy[l(p)] += value;
                lazy[r(p)] += value;
            }
            return;
        }

        ll m = (L + R) / 2;
        update(l(p), L, m, ql, min(qr, m), value);
        update(r(p), m + 1, R, max(ql, m + 1), qr, value);
        s[p] = min(s[l(p)], s[r(p)]);
    }
};

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif

    ll n, q;
    cin >> n;
    vector<ll> a(n);
    for (auto&& ai : a) cin >> ai;
    cin >> q;

    SegmentTree tree(a);
    string line;
    getline(cin, line);
    while (q--) {
        getline(cin, line);
        istringstream ss(line);
        ll l, r, v;
        ss >> l >> r;
        if (ss >> v) {
            if (l > r) {
                tree.update(0, r, v);
                tree.update(l, n - 1, v);
            } else {
                tree.update(l, r, v);
            }
        } else {
            if (l > r) {
                cout << min(tree.query(0, r), tree.query(l, n - 1)) << endl;
            } else {
                cout << tree.query(l, r) << endl;
            }
        }
    }
}
