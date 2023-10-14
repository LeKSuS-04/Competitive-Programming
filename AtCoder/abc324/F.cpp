// Verdict: WA
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
typedef pair<ii, int> iii;
typedef vector<int> vi;

struct Edge {
    int to;
    int beauty;
    int cost;
};

vector<vector<Edge>> AL;

const int INF = 1e12;

ld calc(ii p) {
    if (p.second == 0) {
        return INF + p.second;
    }
    return ((ld)p.first) / ((ld)p.second);
}

struct dist_cmp {
    bool operator()(iii a, iii b) const { return calc(a.first) < calc(b.first); }
};

bool eq(ld a, ld b) { return abs(a - b) < 1e13; }

void solve() {
    int n, m;
    cin >> n >> m;

    AL.assign(n, vector<Edge>());

    for (int i = 0; i < m; i++) {
        int u, v, b, c;
        cin >> u >> v >> b >> c;
        --u, --v;
        AL[u].push_back(Edge{.to = v, .beauty = b, .cost = c});
    }

    priority_queue<iii, vector<iii>, dist_cmp> pq;
    vector<ii> dist;
    pq.push({{0, 0}, 0});
    dist.assign(n, make_pair(-1, 1));
    dist[0] = {0, 0};

    while (!pq.empty()) {
        iii u = pq.top();
        pq.pop();

        if (eq(calc(u.first), calc(dist[u.second]))) {
            for (auto&& v : AL[u.second]) {
                ii bebra = {u.first.first + v.beauty, u.first.second + v.cost};
                if (calc(bebra) > calc(dist[v.to])) {
                    dist[v.to] = bebra;
                    pq.push({dist[v.to], v.to});
                }
            }
        }
    }

    cout << fixed << setprecision(16) << calc(dist[n - 1]) << endl;
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