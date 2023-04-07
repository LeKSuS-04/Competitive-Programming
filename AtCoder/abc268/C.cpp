/* C - Chinese Restaurant */
// https://atcoder.jp/contests/abc268/tasks/abc268_c
// Date: 2022-09-10 15:08:47
// Run time: 54 ms
// Memory: 3996 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> r(n, 0);

    int pi = 0;
    for (int i = 0; i < n; i++) {
        cin >> pi;
        ++r[(pi - i + n - 1) % n];
        ++r[(pi - i + n) % n];
        ++r[(pi - i + n + 1) % n];
    }

    int m = 0;
    for (int i = 0; i < n; i++)
        m = max(r[i], m);

    cout << m << endl;
}