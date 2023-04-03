/* 1805A. We Need the Zero */
// https://codeforces.com/contest/1805/problem/A
// Date: 2023-04-02 17:39:12
// Run time: 15 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        int a = 0;
        for (int i = 0; i < n; i++) {
            int ai;
            cin >> ai;
            a ^= ai;
        }

        if (n % 2 == 1 || a == 0) {
            cout << a << endl;
        } else {
            cout << -1 << endl;
        }
    }
}