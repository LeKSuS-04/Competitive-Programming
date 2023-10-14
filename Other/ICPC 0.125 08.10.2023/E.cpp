// Verdict: AC
// #ifndef LOCALENV
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// #define int ll
typedef pair<int, int> ii;
typedef vector<int> vi;

const int ISLAND = 1;
const int SIDE = 2;

vi type;
vector<vi> AL;

bool is_end(int i) { return AL[i].size() == 1; }

bool is_passthrough(int i) { return AL[i].size() == 2; }

bool is_cross(int i) { return AL[i].size() > 2; }

void solve() {
    int n, m;
    cin >> n >> m;

    type.resize(n);
    AL.resize(n);

    for (auto&& t : type) {
        cin >> t;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        AL[v].push_back(u);
        AL[u].push_back(v);
    }

    queue<int> q, last_point;
    vector<char> visited(n, 0);
    vi dist(n, -1);
    vi p(n, -1);
    vi all_bad_ends;

    for (int i = 0; i < n; i++) {
        if (is_end(i) && type[i] == SIDE) {
            q.push(i);
            all_bad_ends.push_back(i);
            dist[i] = 0;
            p[i] = i;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        bool exit = 0;
        for (const auto& v : AL[u]) {
            if (is_passthrough(v) && !visited[v] && type[v] == SIDE) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                p[v] = u;
                q.push(v);
                exit = true;
            }
        }

        if (exit == false) {
            last_point.push(u);
        }
    }

    while (!last_point.empty()) {
        int u = last_point.front();
        last_point.pop();

        int v = p[u];
        while (v != u) {
            dist[v] = dist[u];
            u = v;
            v = p[u];
        }
    }

    for (int i = 0; i < dist.size(); i++) {
        dist[i]++;
    }

    if (all_bad_ends.size() < 2) {
        cout << n << endl;
        return;
    }

    int mx1 = max(dist[all_bad_ends[0]], dist[all_bad_ends[1]]);
    int mx2 = min(dist[all_bad_ends[0]], dist[all_bad_ends[1]]);
    for (int i = 2; i < all_bad_ends.size(); i++) {
        int d = dist[all_bad_ends[i]];
        if (d >= mx1) {
            mx2 = mx1;
            mx1 = d;
        } else if (d > mx2) {
            mx2 = d;
        }
    }

    int s = 0;
    for (const auto& d : all_bad_ends) {
        s += dist[d];
    }

    cout << n - s + mx1 + mx2 << endl;
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