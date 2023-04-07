/* A - Сумма на отрезке */
// Date: 2022-12-07 12:31:40
// Run time: 842 ms
// Memory: 3892 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class RSQSegmentTree {
   public:
    RSQSegmentTree(int size) : size(size), values(size, 0), segments(4 * size, 0){};

    ll get_sum(int from, int to) { return get_sum(1, from, to, 0, size - 1); }
    void update(int index, ll value) { update(1, 0, size - 1, index, value); }

   private:
    vector<ll> values, segments;
    int size;

    int l(int p) { return (p << 1); }
    int r(int p) { return (p << 1) + 1; }

    ll get_sum(int p, int ql, int qr, int tl, int tr) {
        if (ql > qr || ql < tl || qr > tr) return 0LL;
        if (ql == tl && qr == tr) return segments[p];

        int m = (tl + tr) / 2;
        ll lsubtree = get_sum(l(p),             ql, min(qr, m),    tl,  m);
        ll rsubtree = get_sum(r(p), max(ql, m + 1),         qr, m + 1, tr);
        return lsubtree + rsubtree;
    }

    void update(int p, int tl, int tr, int idx, ll val) {
        if (idx < tl || idx > tr) return;
        if (tl == tr) {
            segments[p] = values[idx] = val;
            return;
        }

        int m = (tl + tr) / 2;
        update(l(p), tl, m, idx, val);
        update(r(p), m + 1, tr, idx, val);
        segments[p] = segments[l(p)] + segments[r(p)];
    }
};

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#else
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;

    RSQSegmentTree stree(n);
    while (k--) {
        char action;
        cin >> action;
        if (action == 'A') {
            int i, x;
            cin >> i >> x;
            stree.update(i - 1, x);
        } else if (action == 'Q') {
            int l, r;
            cin >> l >> r;
            cout << stree.get_sum(l - 1, r - 1) << endl;
        }
    }
}
