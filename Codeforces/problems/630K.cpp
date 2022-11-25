/* 630K. Indivisibility */
// https://codeforces.com/problemset/problem/630/K
// Date: 2022-11-25 20:50:07
// Run time: 15 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    cout << (
        n
        - n/2 - n/3 - n/5 - n/7
        + n/(2*3) + n/(2*5) + n/(2*7) + n/(3*5) + n/(3*7) + n/(5*7)
        - n/(2*3*5) - n/(2*3*7) - n/(2*5*7) - n/(3*5*7)
        + n/(2*3*5*7)
    ) << endl;
}