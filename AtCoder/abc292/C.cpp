/* C - Four Variables */
// https://atcoder.jp/contests/abc292/tasks/abc292_c
// Date: 2023-03-04 15:08:09
// Run time: 970 ms
// Memory: 3536 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll count(ll n) {
    ll answ = 0;
    for (int i = 1; i * i <= n; i++) {
        if (i * i == n) ++answ;
        else if (n % i == 0) answ += 2;
    }
    return answ;
}

int main() {
    int n;
    cin >> n;

    ll answ = 0;
    for (int i = 1; i < n; i++) {
        answ += count(i) * count(n - i);
    }
    cout << answ << endl;
}