/* 276D. Little Girl and Maximum XOR */
// https://codeforces.com/problemset/problem/276/D
// Date: 2022-11-25 21:50:46
// Run time: 0 KB
// Memory: 15 ms
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main() {
    ll l, r, i = 1, p = 0;
    cin >> l >> r;
    while (l | r) {
        if ((l ^ r) & 1) p = i;
        l >>= 1; r >>= 1; ++i;
    }
    cout << (1LL << p) - 1 << endl;
}