/* A. LCA Продолжение */
// Date: 2023-04-02 12:57:50
// Run time: 934 ms
// Memory: 129796 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAX_N = 501'000;
const ll LOG_N = ceil(log2(MAX_N));

vector<vector<ll>> up, AL;
vector<ll> time_in, time_out;
ll timer = 0;

void build(ll u, ll p) {
    up[u][0] = p;
    time_in[u] = timer++;
    for (ll i = 1; i <= LOG_N; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for (ll v : AL[u]) {
        if (v != p) {
            build(v, u);
        }
    }
    time_out[u] = timer++;
}

bool is_ancestor(ll parent, ll child) {
    return time_in[parent] <= time_in[child] && time_out[parent] >= time_out[child];
}

ll lca(ll u, ll v) {
    if (is_ancestor(u, v)) {
        return u;
    } else if (is_ancestor(v, u)) {
        return v;
    }
    for (ll i = LOG_N; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
    freopen("lca.in", "r", stdin);
    freopen("lca.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    up.assign(MAX_N, vector<ll>(LOG_N + 1, 0));
    AL.resize(MAX_N);
    time_in.resize(MAX_N);
    time_out.resize(MAX_N);

    vector<pair<ll, ll>> gets;

    while (n--) {
        string cmd;
        ll u, v;
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