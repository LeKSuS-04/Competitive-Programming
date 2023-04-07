/* E - Transitivity */
// https://atcoder.jp/contests/abc292/tasks/abc292_e
// Date: 2023-03-04 15:35:44
// Run time: 60 ms
// Memory: 3748 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

ll dohash(ii p) { return p.first << 32 + p.second; }
ii unhash(ll h) { return {h >> 32, h & ((1 << 32) - 1)}; }

vector<char> visited;
vector<int> indegree, indegree_all;
vector<vector<int>> AL;

int dfs(int u) {
    if (visited[u]) return 0;
    visited[u] = true;

    int answ = 1;
    for (auto&& v : AL[u]) {
        answ += dfs(v);
    }
    return answ;
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;

    indegree.assign(n, 0);
    AL.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        AL[v].push_back(u);
    }

    int answ = 0;
    for (int i = 0; i < n; i++) {
        visited.assign(n, 0);
        int k = dfs(i);
        answ += k - 1;
    }
    cout << answ - m << endl;
}