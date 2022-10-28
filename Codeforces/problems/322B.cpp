/* 322B. Ciel and Flowers */
// https://codeforces.com/problemset/problem/322/B
// Date: 2022-10-28 10:51:58
// Run time: 30 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    ull r, g, b;
    cin >> r >> g >> b;

    ull x = min(r, min(g, b));
    ull z = max(r, max(g, b));
    ull y = r + g + b - x - z;

    if (x == 0) {
        cout << y / 3 + z / 3 << endl;
    } else if ((z - x) % 3 == 2 || (y - x) % 3 == 2) {
        cout << x-1 + (z-x+1)/3 + (y-x+1)/3 << endl;
    } else {
        cout << x + (y-x)/3 + (z-x)/3 << endl; 
    }
}