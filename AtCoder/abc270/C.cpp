/* C - Simple path */
// https://atcoder.jp/contests/abc270/tasks/abc270_c
// Date: 2022-09-24 15:17:07
// Run time: 237 ms
// Memory: 25292 KB	
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AL;
vector<int> path;

void dfs(int u) {
    for (int i = 0; i < AL[u].size(); i++) {
        int v = AL[u][i];
        if (path[v] == -1) {
            path[v] = u;
            dfs(v);
        }
    }
}

int main() {
    int n, x, y;
    cin >> n >> x >> y; --x; --y;
    path.assign(n, -1);
    AL.assign(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v; --u; --v;
        AL[u].push_back(v);
        AL[v].push_back(u);
    }

    path[x] = x;
    dfs(x);

    vector<int> answ;
    int a = y;
    while (a != x) {
        answ.push_back(a);
        a = path[a];
    }
    answ.push_back(a);

    reverse(answ.begin(), answ.end());
    for (int i = 0; i < answ.size(); i++) {
        cout << answ[i] + 1 << " ";
    }
    cout << endl;
}