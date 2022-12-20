/* D - Make Bipartite 2 */
// https://atcoder.jp/contests/abc282/tasks/abc282_d
// Date: 2022-12-17 15:34:33
// Run time: 186 ms
// Memory: 25008 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> AL;
vector<int> color, visited;
bool is_bipartite = true;

void paint(int u) {
    for (auto&& v : AL[u]) {
        if (visited[v] == 1) {
            is_bipartite &= color[v] != color[u];
        } else {
            if (color[u] % 2 == 0)
                color[v] = color[u] + 1;
            else
                color[v] = color[u] - 1;
            visited[v] = 1;
            paint(v);
        }
    }
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;

    AL.resize(n);
    visited.assign(n, 0);
    color.resize(n);

    for (int i = 0; i < n; i++) {
        color[i] = -i;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        AL[u].push_back(v);
        AL[v].push_back(u);
    }

    int next_color = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            color[i] = next_color;
            next_color += 2;
            paint(i);
        }
    }

    if (!is_bipartite) {
        cout << 0 << endl;
        return 0;
    }

    unordered_map<ll, ll> diffs;
    for (auto&& c : color) {
        if (diffs.find(c) == diffs.end()) {
            diffs[c] = 1;
        } else {
            diffs[c] += 1;
        }
    }

    ll sum = 0;
    for (auto&& [_, d] : diffs) {
        sum += d;
    }
    ll sumsq = sum * sum;
    for (auto&& [_, d] : diffs) {
        sumsq -= d * d;
    }
    cout << sumsq / 2 - m << endl;
}