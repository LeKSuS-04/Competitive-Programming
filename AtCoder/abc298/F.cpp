/* F - Rook Score */
// https://atcoder.jp/contests/abc298/tasks/abc298_f
// Verdict: WA (26/42)

#ifndef LOCALENV
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
typedef pair<int, int> ii;
typedef vector<int> vi;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        uintmax_t hash = std::hash<T1>{}(p.first);
        hash <<= sizeof(uintmax_t) * 4;
        hash ^= std::hash<T2>{}(p.second);
        return std::hash<uintmax_t>{}(hash);
    }
};

void solve() {
    int n;
    cin >> n;
    unordered_map<int, unordered_set<int>> rows, rowsc, cols, colsr;
    unordered_map<ii, int, hash_pair> cells;
    for (int i = 0; i < n; i++) {
        int r, c, v;
        cin >> r >> c >> v;
        if (rows.find(r) == rows.end()) {
            rows[r] = unordered_set<int>();
            rowsc[r] = unordered_set<int>();
        }
        if (cols.find(c) == cols.end()) {
            cols[c] = unordered_set<int>();
            colsr[c] = unordered_set<int>();
        }
        rows[r].insert(v);
        rowsc[r].insert(c);
        cols[c].insert(v);
        colsr[c].insert(r);
        cells[{r, c}] = v;
    }

    unordered_map<int, int> rsum, csum;
    set<ii> rsumo, csumo;
    for (auto&& [v, arr] : rows) {
        rsum[v] = reduce(arr.begin(), arr.end(), 0, [](int x, int y) { return x + y; });
        rsumo.insert({rsum[v], v});
    }
    for (auto&& [v, arr] : cols) {
        csum[v] = reduce(arr.begin(), arr.end(), 0, [](int x, int y) { return x + y; });
        csumo.insert({csum[v], v});
    }

    auto [mxrv, mxr] = *rsumo.rbegin();
    auto [mxcv, mxc] = *csumo.rbegin();

    int sum = -1;
    for (auto&& [k, v] : cells) {
        auto [r, c] = k;
        sum = max(sum, rsum[r] + csum[c] - v);
        sum = max(sum, rsum[r] + mxcv - (rowsc[r].find(mxc) == rowsc[r].end() ? 0 : cells[{r, mxc}]));
        sum = max(sum, csum[c] + mxrv - (colsr[c].find(mxr) == colsr[c].end() ? 0 : cells[{mxr, c}]));
    }

    cout << sum << endl;
}

signed main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC = 1;
    // cin >> TC;
    while (TC--) {
        solve();
    }
    cout.flush();
}