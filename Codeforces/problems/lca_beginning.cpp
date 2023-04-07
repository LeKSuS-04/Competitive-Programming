/* A. LCA Начало */
// Date: 2023-04-02 12:54:57
// Run time: 0 ms
// Memory: 176 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;
const int LOG_N = ceil(log2(MAX_N));

vector<vector<int>> up, AL;
vector<int> time_in, time_out;
int timer = 0;

void build(int u, int p) {
    up[u][0] = p;
    time_in[u] = timer++;
    for (int i = 1; i <= LOG_N; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for (int v : AL[u]) {
        if (v != p) {
            build(v, u);
        }
    }
    time_out[u] = timer++;
}

bool is_ancestor(int parent, int child) {
    return time_in[parent] <= time_in[child] && time_out[parent] >= time_out[child];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) {
        return u;
    } else if (is_ancestor(v, u)) {
        return v;
    }
    for (int i = LOG_N; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
    freopen("lca.in", "r", stdin);
    freopen("lca.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    up.assign(MAX_N, vector<int>(LOG_N + 1, 0));
    AL.resize(MAX_N);
    time_in.resize(MAX_N);
    time_out.resize(MAX_N);

    vector<pair<int, int>> gets;

    while (n--) {
        string cmd;
        int u, v;
        cin >> cmd >> u >> v;
        --u, --v;
        if (cmd == "ADD") {
            AL[u].push_back(v);
            AL[v].push_back(u);
        } else if (cmd == "GET") {
            gets.push_back({u, v});
        }
    }

    build(0, 0);

    for (auto&& [u, v] : gets) {
        cout << lca(u, v) + 1 << '\n';
    }
    cout.flush();
}