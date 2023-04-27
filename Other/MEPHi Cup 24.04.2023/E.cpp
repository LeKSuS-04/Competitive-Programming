// Verdict: WA(7)

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

vector<vi> AL;
vi e;
vector<char> visited;

ii dfs(int u) {
    visited[u] = true;
    set<ii, greater<ii>> a, b;
    a.insert({0, -1});
    b.insert({0, -1});
    for (int v : AL[u]) {
        if (!visited[v]) {
            auto [c, d] = dfs(v);
            a.insert({d + e[u] + e[v], v});
            b.insert({c, v});
        }
    }

    ii p;
    p.second = 0;
    for (auto [t, r] : b) {
        p.second += t;
    }
    int cntr = 0;
    while (cntr < 100) {
        if (a.rbegin()) {
        }
    }
    if (a.rbegin()->second != b.rbegin()->second) {
        p.first = a.rbegin()->first + b.rbegin()->first;
    } else {
        if (a.size() == 1 && b.size() == 1) {
            p.first = a.rbegin()->first;
        } else if (a.size() == 1) {
            p.first = a.rbegin()->first + next(b.rbegin())->first;
        } else if (b.size() == 1) {
            p.first = max(a.rbegin()->first, b.rbegin()->first + next(a.rbegin())->first);
        } else {
            p.first = max(a.rbegin()->first + next(b.rbegin())->first,
                          b.rbegin()->first + next(a.rbegin())->first);
        }
    }
    return p;
}

void solve() {
    int n;
    cin >> n;
    AL.resize(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        --p;
        AL[p].push_back(i);
        AL[i].push_back(p);
    }

    e.resize(n);
    for (auto&& ei : e) {
        cin >> ei;
    }

    visited.assign(n, false);
    auto [a, b] = dfs(0);

    cout << max(a, b) << endl;
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