/* 1808A. Lucky Numbers */
// https://codeforces.com/contest/1808/problem/A
// Date: 2023-04-03 21:47:17
// Run time: 77 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int luck(int n) {
    if (n == 0) return -1;
    int mn = 10, mx = -1;
    while (n != 0) {
        int t = n % 10;
        n /= 10;
        mn = min(mn, t);
        mx = max(mx, t);
    }
    return mx - mn;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int l, r;
        cin >> l >> r;

        int best = 0;
        for (int i = l; i <= r; i++) {
            if (luck(i) > luck(best)) {
                best = i;
                if (luck(best) == 9) {
                    break;
                }
            }
        }
        cout << best << endl;
    }
    cout.flush();
}