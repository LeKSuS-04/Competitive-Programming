/* 333A. Secrets */
// https://codeforces.com/problemset/problem/333/A
// Date: Sep/11/2022 20:10
// Run time: 30 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    ll i = 3;
    while (i <= n) {
        if (n % i != 0) {
            cout << (n + i - 1) / i << endl;
            return 0;
        }
        i *= 3;
    }
    cout << 1 << endl;
}