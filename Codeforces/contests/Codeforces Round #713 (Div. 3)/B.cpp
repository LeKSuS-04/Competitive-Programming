/* 1512B. Almost Rectangle */
// https://codeforces.com/contest/1512/problem/B
// Date: Sep/17/2022 15:07
// Run time: 30 ms
// Memory: 200 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int TC; cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));

        vector<pair<int, int>> coords;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
                if (a[i][j] == '*') {
                    coords.push_back({i, j});
                }
            }

        int tx = min(coords[0].second, coords[1].second);
        int lx = max(coords[0].second, coords[1].second);
        int ty = min(coords[0].first, coords[1].first);
        int ly = max(coords[0].first, coords[1].first);

        if (tx == lx) {
            tx = (lx + 1) % n;
        }
        if (ty == ly) {
            ty = (ly + 1) % n;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == ty && j == tx) ||
                    (i == ty && j == lx) ||
                    (i == ly && j == tx) ||
                    (i == ly && j == lx )) {
                        cout << '*';
                    }
                else cout << '.';
            }
            cout << endl;
        }
    }
}