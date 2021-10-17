/* C - Omkar and Determination */
// https://codeforces.com/contest/1583/problem/C
// Date: Oct/17/2021 15:31 (01:26:41)
// Runtime: 1169 ms	
// Memory: 400 KB
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    int n;
    vector<bool> A, st;

    int l(int p) { return (p << 1); }
    int r(int p) { return (p << 1) + 1; }

    void build(int p, int L, int R) {
        if (L == R) st[p] = A[L];
        else {
            int m = (L + R)/2;
            build(l(p),     L, m);
            build(r(p), m + 1, R);
            st[p] = (st[l(p)] || st[r(p)]);
        }
    }

    int answ(int p, int L, int R, int i, int j) {
        if (i > j) return -1;
        if (i <= L && j >= R) return st[p];

        int m = (L + R) / 2;
        int lsubtree = answ(l(p),     L, m,             i, min(j, m));
        int rsubtree = answ(r(p), m + 1, R, max(i, m + 1),         j);

        if (lsubtree == -1) return rsubtree;
        if (rsubtree == -1) return lsubtree;

        return (lsubtree || rsubtree);
    }
public:
    SegmentTree(vector<bool> v = {})  {
        n = v.size();
        st.resize(4 * n);
        A = v;
        build(1, 0, n - 1);
    }

    bool answ(int i, int j) { return answ(1, 0, n - 1, i, j); }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> is_empty(n, vector<bool>(m));
    for (int i = 0 ; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++)
            is_empty[i][j] = (line[j] == '.');
    }
    
    vector<bool> contains_bad_beginning(m, false);
    for (int i = 1; i < n; i++) 
        for (int j = 0; j < m - 1; j++) 
            if (!is_empty[i][j] && !is_empty[i - 1][j + 1])
                contains_bad_beginning[j] = true;
    SegmentTree ST(contains_bad_beginning);
                
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        a -= 1; b -= 1;

        if (a == b) cout << "YES\n";
        else {
            if (ST.answ(a, b - 1)) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}