/* D - Экзамен */
// Date: 2022-12-08 20:52:42
// Run time: 1370 ms
// Memory: 964 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 200'010;

template <class T>
class SegmentTree {
   public:
    SegmentTree(int size, function<T(T, T)> func)
        : size(size), values(size, 0), segments(4 * size, 0), func(func){};

    T query(int from, int to) { return query(1, from, to, 0, size - 1); }
    void update(int index, T value) { update(1, 0, size - 1, index, value); }

   private:
    static const int INVALID = -1;

    int size;
    vector<T> values, segments;
    function<T(T, T)> func;

    int l(int p) { return (p << 1); }
    int r(int p) { return (p << 1) + 1; }

    T query(int p, int ql, int qr, int tl, int tr) {
        if (ql > qr) return INVALID;
        if (ql == tl && qr == tr) return segments[p];

        int m = (tl + tr) / 2;
        T lsubtree = query(l(p), ql, min(qr, m), tl, m);
        T rsubtree = query(r(p), max(ql, m + 1), qr, m + 1, tr);

        if (lsubtree == INVALID) return rsubtree;
        if (rsubtree == INVALID) return lsubtree;
        return func(lsubtree, rsubtree);
    }

    void update(int p, int tl, int tr, int index, T value) {
        if (index < tl || index > tr) return;
        if (tl == tr) {
            values[index] = segments[p] = value;
            return;
        }

        int m = (tl + tr) / 2;
        update(l(p), tl, m, index, value);
        update(r(p), m + 1, tr, index, value);
        segments[p] = func(segments[l(p)], segments[r(p)]);
    }
};

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#else
    freopen("exam.in", "r", stdin);
    freopen("exam.out", "w", stdout);
#endif

    int n;
    cin >> n;

    SegmentTree<char> rmq(MAX_SIZE, [](char a, char b) { return min(a, b); });

    int q;
    while (n--) {
        cin >> q;
        if (q > 0) {
            int l = q - 1, r = MAX_SIZE - 1;
            while (r - l != 1) {
                int m = (r + l) / 2;
                if (rmq.query(q, m) == 0) r = m;
                else l = m;
            }
            rmq.update(r, 1);
            cout << r << endl;
        } else {
            rmq.update(-q, 0);
        }
    }
}