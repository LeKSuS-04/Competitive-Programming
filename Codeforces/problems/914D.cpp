#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
   public:
    SegmentTree(vector<int>& values) : values(values) {
        st.resize(4 * values.size());
        build(1, 0, values.size() - 1);
    }

    int query(int l, int r) { return query(1, 0, values.size() - 1, l - 1, r - 1); }
    void update(int idx, int value) { return update(1, 0, values.size() - 1, idx - 1, value); }

   private:
    vector<int> st, values;
    const int INVALID = -1;

    int l(int p) { return p << 1; }
    int r(int p) { return (p << 1) + 1; }

    void build(int p, int tl, int tr) {
        if (tl == tr) {
            st[p] = values[tl];
            return;
        }

        int m = (tl + tr) / 2;
        build(l(p), tl, m);
        build(r(p), m + 1, tr);
        st[p] = gcd(st[l(p)], st[r(p)]);
    }

    int query(int p, int tl, int tr, int ql, int qr) {
        if (ql > tr || qr < tl) return INVALID;
        if (ql <= tl && tr <= ql) return st[p];

        int m = (tl + tr) / 2;
        int lsubtree = query(l(p), tl, m, ql, min(m, qr));
        int rsubtree = query(r(p), m + 1, tr, max(ql, m + 1), qr);

        if (lsubtree == INVALID) return rsubtree;
        if (rsubtree == INVALID) return lsubtree;

        return gcd(lsubtree, rsubtree);
    }

    void update(int p, int tl, int tr, int idx, int val) {
        if (idx < tl || idx > tr) return;
        if (tr == tl) {
            values[idx] = st[p] = val;
            return;
        }

        int m = (tl + tr) / 2;
        update(l(p), tl, m, idx, val);
        update(r(p), m + 1, tr, idx, val);
        st[p] = gcd(st[l(p)], st[r(p)]);
    }
};

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto&& ai : arr) cin >> ai;

    SegmentTree tree(arr);

    int q;
    cin >> q;
    while (q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int l, r, x;
            cin >> l >> r >> x;

            bool possible = true;
            while (r != l) {
                int m = (l + r) / 2;
                int lgcd = tree.query(l, m);
                int rgcd = tree.query(m + 1, r);
                if (lgcd % x != 0 && rgcd % x != 0) {
                    possible = false;
                    break;
                }
                if (lgcd % x == 0 && rgcd % x == 0) {
                    break;
                }

                if (lgcd % x == 0) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }

            cout << (possible ? "YES" : "NO") << '\n';
        } else {
            int i, y;
            cin >> i >> y;
            tree.update(i, y);
        }
    }
}