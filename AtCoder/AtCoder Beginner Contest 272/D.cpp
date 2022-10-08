/* D. Root M Leaper */
// https://atcoder.jp/contests/abc272/tasks/abc272_d
// Date: 2022-10-08 15:24:07
// Run time: 47 ms
// Memory: 4756 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> d;
    for (ll i = 0; i * i <= m; i++) {
        for (ll j = i; i * i + j * j <= m; j++) {
            if (i * i + j * j == (long long) m) {
                d.push_back({i, j});
                d.push_back({-i, j});
                d.push_back({i, -j});
                d.push_back({-i, -j});
                d.push_back({j, i});
                d.push_back({-j, i});
                d.push_back({j, -i});
                d.push_back({-j, -i});
            }
        }
    }

    queue<pair<int, int>> q;
    vector<vector<int>> p(n, vector<int>(n, -1));
    p[0][0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (auto&& di : d) {
            pair<int, int> v = {u.first + di.first, u.second + di.second};
            if (v.first >= 0 && v.first < n && v.second >= 0 && v.second < n &&
                p[v.first][v.second] == -1) {
                    p[v.first][v.second] = 1 + p[u.first][u.second];
                    q.push(v);
                }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << p[i][j] << ' ';
        }
        cout << '\n';
    }
}