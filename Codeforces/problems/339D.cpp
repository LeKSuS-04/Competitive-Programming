/* 339D. Xenia and Bit Operations */
// https://codeforces.com/contest/339/problem/D
// Date: Aug/19/2021 13:44
// Run time: 1682 ms
// Memory: 7200 KB
// Verdict: AC

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

const int XOR = 0;
const int  OR = 1;

class SegmentTree {
private:
    int n, depth;
    vector<int> A, st;

    int l(int p) { return (p << 1); }
    int r(int p) { return (p << 1) + 1; }

    void build(int p, int L, int R, int operation) {
        if (L == R) st[p] = A[L];
        else {
            int m = (L + R) / 2;
            build(l(p),     L, m, operation ^ 1);
            build(r(p), m + 1, R, operation ^ 1);
            st[p] = (operation == OR ? st[l(p)] | st[r(p)] : st[l(p)] ^ st[r(p)]);
        }
    }

    void update(int p, int L, int R, int i, int val, int operation) {
        if (i < L || i > R) return;
        if (L == R) {
            st[p] = A[i] = val;
        } else {
            int m = (L + R) / 2;
            update(l(p),     L, m, i, val, operation ^ 1);
            update(r(p), m + 1, R, i, val, operation ^ 1);
            st[p] = (operation == OR ? st[l(p)] | st[r(p)] : st[l(p)] ^ st[r(p)]);
        }
    }
public:
    SegmentTree(int size) : n(size), st(4 * size) {}
    SegmentTree(vector<int> v, int d) : SegmentTree((int)v.size()) {
        A = v; depth = d;
        build(1, 0, n - 1, depth % 2);
    }

    void update(int i, int val) { update(1, 0, n - 1, i, val, depth % 2); };
    int calc() { return st[1]; };
};

int main() {
    int n, m, p, b;
    cin >> n >> m;

    vector<int> v((int)pow(2, n));
    for (int i = 0; i < (int)pow(2, n); i++) cin >> v[i];

    SegmentTree tree(v, n);
    while (m--) {
        cin >> p >> b;
        tree.update(p - 1, b);
        cout << tree.calc() << endl;
    }
}