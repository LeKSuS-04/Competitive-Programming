// Verdict: AC
// #ifndef LOCALENV
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
typedef pair<int, int> ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int> vi;

const int INF = 1LL << 60LL;

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<vector<int>> AM(n, vector<int>(n));
    for (auto&& line : AM) {
        for (auto&& vi : line) {
            cin >> vi;
        }
    }

    vector<priority_queue<ii, vector<ii>, greater<ii>>> pq(2);
    vector<vector<int>> dist(2, vector<int>(n, INF));
    priority_queue<ii, vector<ii>, greater<ii>> pq_tr;
    vector<int> dist_tr(n, INF);
    pq[0].push({0, 0});
    pq[1].push({0, n - 1});
    dist[0][0] = dist[1][n - 1] = 0;

    for (int i = 0; i < 2; i++) {
        while (!pq[i].empty()) {
            auto [w, u] = pq[i].top();
            pq[i].pop();

            if (w > dist[i][u]) {
                continue;
            }

            for (int v = 0; v < n; v++) {
                if (v == u) continue;

                int new_w = w + (i == 0 ? AM[u][v] * a : AM[u][v] * b + c);
                if (new_w < dist[i][v]) {
                    dist[i][v] = new_w;
                    pq[i].push({new_w, v});
                }
            }
        }
    }

    int mn = INF;
    for (int i = 0; i < n; i++) {
        mn = min(mn, dist[0][i] + dist[1][i]);
    }

    cout << mn << endl;
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