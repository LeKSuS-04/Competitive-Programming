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

const int INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<ii>> AL(n);
    vector<pair<ii, int>> edges;

    // https://codeforces.com/problemset/gymProblem/101498/L
    
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        AL[u].push_back({v, w});
    }

    vi dist(n, INF);
    int root = 0;
    dist[root] = 0;
    int c = 0;
    bool changed = true, has_neg_cycle = false;
    while (changed) {
        changed = false;
        for (int u = 0; u < n; u++) {
            for (auto [v, w] : AL[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    changed = true;
                }
            }
        }

        c++;
        if (c > n - 1) {
            has_neg_cycle = true;
            break;
        }
    }

    if (has_neg_cycle) {
        cout << "-inf\n";
    } else {
        auto dijkstra = [&AL, &n](int root) {
            vector<int> dist(n, INF);
            priority_queue<ii, vector<ii>, greater<ii>> pq;
            dist[root] = 0;
            pq.push({dist[root], root});
            while (!pq.empty()) {
                auto [check_w, u] = pq.top();
                pq.pop();
                if (check_w != dist[u]) continue;
                for (auto [v, w] : AL[u]) {
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }
            int m = INF;
            for (int i = 0; i < n; i++) {
                if (i != root) {
                    m = min(m, dist[i]);
                }
            }
            return m;
        };

        int answ = INF;
        for (int i = 0; i < n; i++) {
            answ = min(answ, dijkstra(i));
        }
        cout << answ << '\n';
    }
}

signed main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC = 1;
    cin >> TC;
    while (TC--) {
        solve();
    }
    cout.flush();
}