/* 1516B. AGAGA XOOORRR */
// https://codeforces.com/problemset/problem/1516/B
// Date: 20.08.2021 19:13
// Run time: 295 ms
// Memory: 19500 KB
// Verdict: AC

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int memo[2010][2010];
vector<int> a;

int xor_range(int l, int r) {
    if (l == r) return 0;
    if (memo[l][r] != -1) return memo[l][r];

    return memo[l][r] = a[l] ^ xor_range(l + 1, r);
}

bool brute_xor() {
    int x, y, z;
    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            if (i == 0) {
                x = xor_range(i, j), y = xor_range(j, a.size());
                if (x == y) return true;
            } else {
                x = xor_range(0, i), y = xor_range(i, j), z = xor_range(j, a.size());
                if (x == y && y == z) return true;
            }
        }
    }
    return false;
}

int main() {
    int TC, n;
    cin >> TC;

    while (TC--) {
        cin >> n;
        a.assign(n, 0);
        memset(memo, -1, sizeof memo);
        for (int i = 0; i < n; i++) cin >> a[i];

        if (brute_xor()) cout << "YES\n";
        else cout << "NO\n";
    }
}