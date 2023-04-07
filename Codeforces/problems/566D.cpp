/* 566D. Restructuring Company */
// https://codeforces.com/contest/566/problem/D
// Date:
// Run time: 234 ms
// Memory: 2400 KB
// Verdict: AC

#ifndef LOCALENV
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

class UFDS {
   private:
    vector<int> p, rank, next;

   public:
    UFDS(int n) {
        rank.assign(n, 0);
        p.resize(n);
        next.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
            next[i] = i + 1;
        }
    }

    int find_set(int i) { return p[i] == i ? i : p[i] = find_set(p[i]); }
    bool same_set(int i, int j) { return find_set(i) == find_set(j); }
    void merge(int i, int j) {
        if (!same_set(i, j)) {
            int x = find_set(i);
            int y = find_set(j);
            if (rank[x] > rank[y]) swap(x, y);
            if (rank[x] == rank[y]) ++rank[y];
            p[x] = y;
        }
    }
    void merge_range(int l, int r) {
        if (r < l) swap(l, r);
        ++l;
        while (l <= r) {
            merge(l - 1, l);
            int t = next[l];
            next[l] = max(next[l], r);
            l = t;
        }
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    UFDS ufds(n);
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        --x, --y;
        if (t == 1) {
            ufds.merge(x, y);
        } else if (t == 2) {
            ufds.merge_range(x, y);
        } else {
            cout << (ufds.same_set(x, y) ? "YES\n" : "NO\n");
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC = 1;
    // cin >> TC;
    while (TC--) {
        solve();
    }
    cout.flush();
}