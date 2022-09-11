/* 279B. Books */
// https://codeforces.com/problemset/problem/279/B
// Date: Sep/11/2022 10:20
// Run time: 248 ms
// Memory: 400 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    for (auto&& ai : a) cin >> ai;

    int l, r, s, c, m;
    l = r = s = c = m = 0;
    while (r < n) {
        if (s + a[r] <= t) {
            s += a[r++];
            m = max(m, ++c);
        } else {
            s -= a[l++];
            --c;
        }
    }

    cout << m << endl;
}