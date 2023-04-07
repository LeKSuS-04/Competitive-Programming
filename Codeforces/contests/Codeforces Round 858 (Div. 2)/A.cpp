/* 1806A. Walking Master */
// https://codeforces.com/contest/1806/problem/A
// Date: 2023-03-18 15:12:10
// Run time: 93 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif

    int TC;
    cin >> TC;
    while (TC--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int dy = d - b;
        int dx = (a + dy) - c;
        if (dy < 0 || dx < 0) cout << -1 << endl;
        else cout << dy + dx << endl;
    }
}