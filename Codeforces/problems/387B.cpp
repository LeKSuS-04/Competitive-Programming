/* 387B. George and Round */
// https://codeforces.com/problemset/problem/387/B
// Date: Sep/11/2022 11:45
// Run time: 31 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto&& ai : a) cin >> ai;
    for (auto&& bi : b) cin >> bi;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0, c = 0;
    while (i < n) {
        while (j < m && a[i] > b[j]) ++j;
        if (j == m) ++c;
        else ++j;
        ++i;
    }

    cout << c << endl;
}