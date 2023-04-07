/* 825E. Minimal Labels */
// https://codeforces.com/problemset/problem/825/E
// Date: 2023-03-30 17:03:29
// Run time: 312 ms
// Memory: 7800 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AL;
vector<int> outdegree;

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;

    AL.resize(n);
    outdegree.assign(n, 0);
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        swap(u, v);
        AL[u].push_back(v);
        outdegree[v]++;
    }

    set<int> outdegree_zero;
    for (int i = 0; i < n; i++) {
        if (outdegree[i] == 0) {
            outdegree_zero.insert(i);
        }
    }

    vector<int> label(n);
    for (int current_label = n; current_label > 0; current_label--) {
        auto u = prev(outdegree_zero.end());
        label[*u] = current_label;
        outdegree_zero.erase(u);
        for (auto&& v : AL[*u]) {
            --outdegree[v];
            if (outdegree[v] == 0) {
                outdegree_zero.insert(v);
            }
        }
    }

    for (auto&& label_i : label) {
        cout << label_i << ' ';
    }
    cout << endl;
}