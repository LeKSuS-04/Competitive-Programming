/* 1730B. Meeting on the Line */
// https://codeforces.com/problemset/problem/1730/B
// Date: 2022-10-19 19:20:07
// Run time: 1950 ms
// Memory: 3132 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

const ld E = 1e-6;

int n;
vector<ld> x;
vector<ld> t;

ld max_time(ld pos) {
    ld maxi = 0;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, fabsl(x[i] - pos) + t[i]);
    }
    return maxi;
}

int main() {
    #ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
    #endif
    
    int TC;
    cin >> TC;

    while (TC--) {
        cin >> n;
        x.resize(n);
        t.resize(n);
        for (auto&& xi : x) cin >> xi;
        for (auto&& ti : t) cin >> ti;

        ld l = 0;
        ld r = 10e8;
        ld m1, m2;
        while (r - l > E) {
            m1 = l + (r - l)/3;
            m2 = r - (r - l)/3;
            if (max_time(m1) > max_time(m2)) l = m1;
            else r = m2;
        }

        cout << fixed << setprecision(7) << r << endl;
    }
}