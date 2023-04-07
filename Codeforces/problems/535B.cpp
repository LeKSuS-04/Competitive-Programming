/* 535B. Tavas and SaDDas */
// https://codeforces.com/problemset/problem/535/B
// Date: 2022-11-25 22:10:47
// Run time: 15 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int make_happy(int n) {
    int out = 0, p = 1;
    while (n > 1) {
        if (n & 1) out += 7*p;
        else out += 4*p;
        n >>= 1;
        p *= 10;
    }
    return out;
}

int main() {
    int n, i = 2;
    cin >> n;
    while (make_happy(i) != n) ++i;
    cout << i - 1 << endl;
}