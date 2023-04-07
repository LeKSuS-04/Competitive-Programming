/* 25D. Roads not only in Berland */
// https://codeforces.com/problemset/problem/25/D
// Date: 2023-04-06 00:35:45
// Run time: 30 ms
// Memory: 100 KB
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
   public:
    vector<int> p, rank;

    UFDS(int n) {
        p.resize(n);
        rank.assign(n, 1);
        for (int i = 0; i < n; i++) {
            p[i] = i;
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
};

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> bad;
    UFDS ufds(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (ufds.same_set(u, v)) {
            bad.push_back({u, v});
        } else {
            ufds.merge(u, v);
        }
    }
    set<int> sets;
    for (int i = 0; i < n; i++) {
        sets.insert(ufds.find_set(i));
    }

    vector<vector<int>> answer;
    for (auto it = next(sets.begin()); it != sets.end(); it++) {
        if (!ufds.same_set(*sets.begin(), *it)) {
            auto [u, v] = bad.back();
            answer.push_back(vector<int>());
            answer.back().push_back(1 + u);
            answer.back().push_back(1 + v);
            answer.back().push_back(1 + *it);
            answer.back().push_back(1 + *sets.begin());
            bad.pop_back();
            ufds.merge(*sets.begin(), *it);
        }
    }

    cout << answer.size() << '\n';
    for (auto&& an : answer) {
        for (auto&& a : an) {
            cout << a << ' ';
        }
        cout << '\n';
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