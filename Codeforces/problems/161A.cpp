/* 161A. Dress'em in Vests! */
// https://codeforces.com/problemset/problem/161/A?locale=ru
// Date: Sep/11/2022 18:09
// Run time: 1278 ms
// Memory: 2900 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> a(n), b(m);
    for (auto&& ai : a) cin >> ai;
    for (auto&& bi : b) cin >> bi;

    vector<ii> answ;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < m && b[j] < a[i] - x)
            ++j;
        if (j < m && a[i] - x <= b[j] && b[j] <= a[i] + y) {
            answ.push_back({i + 1, j + 1});
            ++j;
        }
    }

    cout << answ.size() << endl;
    for (auto&& t : answ)
        cout << t.first << ' ' << t.second << endl;
}