/* 67A. Partial Teacher */
// https://codeforces.com/problemset/problem/67/A
// Date: 2023-03-15 14:11:57
// Run time: 30 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif

    int n;
    string s;
    cin >> n >> s;

    vector<vector<pair<int, int>>> AL(n);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R') {
            AL[i].push_back({i + 1, 1});
        } else if (s[i] == 'L') {
            AL[i + 1].push_back({i, 1});
        } else {
            AL[i].push_back({i + 1, 0});
            AL[i + 1].push_back({i, 0});
        }
    }

    vector<int> cost(n, -1);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        bool push = ((i == 0 && (s[i] == '=' || s[i] == 'R')) ||
                     (i == n - 1 && (s[i - 1] == '=' || s[i - 1] == 'L')) ||
                     (i != 0 && i != n - 1 && (s[i - 1] == '=' || s[i - 1] == 'L') &&
                      (s[i] == 'R' || s[i] == '=')));
        if (push) {
            q.push(i);
            cost[i] = 1;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto&& [v, w] : AL[u]) {
            if (cost[v] < cost[u] + w) {
                cost[v] = cost[u] + w;
                q.push(v);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << cost[i] << ' ';
    }
    cout << endl;
}