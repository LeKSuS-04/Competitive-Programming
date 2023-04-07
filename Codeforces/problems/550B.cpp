/* 550B. Preparing Olympiad */
// https://codeforces.com/problemset/problem/550/B
// Date: 2022-11-22 21:17:36
// Run time: 15 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
    #endif
    
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<int> c(n);
    for (auto&& ci : c) cin >> ci;

    int answer = 0;
    for (int i = 0; i < (1 << n); i++) {
        int total = 0, cnt = 0, mn = 1e7, mx = 0;
        for (int j = 0; (1 << j) <= i; j += 1) {
            if (i & (1 << j)) {
                cnt += 1;
                total += c[j];
                mn = min(c[j], mn);
                mx = max(c[j], mx);
            }
        }

        if (cnt > 1 && mx - mn >= x && l <= total && total <= r) {
            ++answer;
        }
    }

    cout << answer << endl;
}