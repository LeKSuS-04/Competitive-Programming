/* 706B. Interesting drink */
// https://codeforces.com/problemset/problem/706/B
// Date: 2022-10-13 14:37:57
// Run time: 592 ms
// Memory: 372 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (auto&& xi : x) cin >> xi;
    sort(x.begin(), x.end());
    
    int q, m;
    cin >> q;
    while (q--) {
        cin >> m;
        cout << lower_bound(x.begin(), x.end(), m + 1) - x.begin() << endl;
    }
}