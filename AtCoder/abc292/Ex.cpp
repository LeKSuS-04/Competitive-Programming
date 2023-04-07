/* Ex - Rating Estimator */
// https://atcoder.jp/contests/abc292/tasks/abc292_h
// Verdict: Not submitted

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> a;

class SegmentTree {
   public:
    SegmentTree(vector<ll>& v) {
        values.resize(v.size());
        for (int i = 0; i < v.size(); i++) {
            values[i] = i;
        }
        st.resize(4 * values.size());
        build(1, 0, values.size() - 1);
    }

    ll query(ll l, ll r) { return query(1, 0, values.size() - 1, l - 1, r - 1); }
    void update(ll idx, ll value) { return update(1, 0, values.size() - 1, idx - 1, value); }

   private:
    vector<ll> st, values;
    const ll INVALID = -1;

    ll l(ll p) { return p << 1; }
    ll r(ll p) { return (p << 1) + 1; }

    ll max_i(ll i, ll j) {
        if (a[i] >= a[j]) return i;
        return j;
    }

    void build(ll p, ll tl, ll tr) {
        if (tl == tr) {
            st[p] = values[tl];
            return;
        }

        ll m = (tl + tr) / 2;
        build(l(p), tl, m);
        build(r(p), m + 1, tr);
        st[p] = max_i(st[l(p)], st[r(p)]);
    }

    ll query(ll p, ll tl, ll tr, ll ql, ll qr) {
        if (ql > tr || qr < tl) return INVALID;
        if (ql <= tl && tr <= ql) return st[p];

        ll m = (tl + tr) / 2;
        ll lsubtree = query(l(p), tl, m, ql, min(m, qr));
        ll rsubtree = query(r(p), m + 1, tr, max(ql, m + 1), qr);

        if (lsubtree == INVALID) return rsubtree;
        if (rsubtree == INVALID) return lsubtree;

        return max_i(lsubtree, rsubtree);
    }

    void update(ll p, ll tl, ll tr, ll idx, ll val) {
        if (idx < tl || idx > tr) return;
        if (tr == tl) {
            values[idx] = st[p] = val;
            return;
        }

        ll m = (tl + tr) / 2;
        update(l(p), tl, m, idx, val);
        update(r(p), m + 1, tr, idx, val);
        st[p] = max_i(st[l(p)], st[r(p)]);
    }
};

class FenwickTree {
   public:
    FenwickTree(const vector<ll>& v) : ft(v.size() + 1) {
        for (ll i = 0; i < v.size(); i++) {
            add(i, v[i]);
        }
    }

    ll lsb(ll n) { return n & -n; }

    ll sum(ll r) {
        ll res = 0;
        for (; r > 0; r -= lsb(r)) {
            res += ft[r];
        }
        return res;
    }

    ll sum(ll l, ll r) { return sum(r + 1) - sum(l); }
    double raiting(ll r) { return ((double)sum(r + 1)) / ((double)(r + 1)); }

    void add(ll i, ll val) {
        i += 1;
        for (; i < ft.size(); i += lsb(i)) {
            ft[i] += val;
        }
    }

   private:
    vector<ll> ft;
};

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(9);

    ll n, q;
    double b;
    cin >> n >> b >> q;

    a.resize(n);
    for (auto&& ai : a) cin >> ai;
    FenwickTree ftree(a);

    SegmentTree max_on_postfix(a);

    while (q--) {
        ll c, x;
        cin >> c >> x;

        --c;
        ftree.add(c, x - a[c]);
        if (x > a[c]) {
            ll mx = max_on_postfix.query(c, n - 1);
            if (ftree.raiting(mx) >= b) {
                cout << ftree.raiting(mx) << endl;
            } else {
                cout << ftree.raiting(n) << endl;
            }
        } else {
            cout << ftree.raiting(n) << endl;
        }

        max_on_postfix.update(c, x);
        a[c] = x;
    }
}