/* C - Gap Existence */
// https://atcoder.jp/contests/abc296/tasks/abc296_c
// Date: 2023-04-01 15:08:20
// Run time: 12252 KB
// Memory: 115 ms
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif

    int n, x;
    cin >> n >> x;

    unordered_set<int> seen;
    vector<int> a(n);
    for (auto&& ai : a) {
        cin >> ai;
        seen.insert(ai);
    }

    for (int i = 0; i < n; i++) {
        int g = a[i] + x;
        if (seen.find(g) != seen.end()) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}