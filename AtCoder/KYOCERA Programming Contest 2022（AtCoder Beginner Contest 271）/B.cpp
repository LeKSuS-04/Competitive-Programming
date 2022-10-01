/* B - Maintain Multiple Sequences */
// https://atcoder.jp/contests/abc271/tasks/abc271_b
// Date: 2022-10-01 15:04:56
// Run time: 436 ms
// Memory: 13984 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n  >> q;

    vector<vector<int>> l(n);
    for (int i = 0; i < n; i++) {
        int li; cin >> li;
        l[i].resize(li);
        for (auto&& x : l[i])
            cin >> x;
    }

    while (q--) {
        int i, j;
        cin >> i >> j;
        cout << l[i-1][j-1] << endl;
    }
}