/* 251A. Points on Line */
// https://codeforces.com/problemset/problem/251/A
// Date: Sep/11/2022 14:49 
// Run time: 374 ms
// Memory: 400 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> x(n);
    for (auto&& xi : x) cin >> xi;

    ll r = 0;
    ll s = 0;
    for (ll l = 0; l < n - 2; l++) {
        while (r < n && x[r] - x[l] <= d) ++r;
        s += max(0LL, (r-l-1) * (r-l-2) / 2);
        if (r - l < 2) r = l + 2;
    }

    cout << s << endl;
}