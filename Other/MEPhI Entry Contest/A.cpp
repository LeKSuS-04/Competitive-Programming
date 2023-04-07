/* A. Скалярное произведение */
// Date: 1 Sep 2022, 10:02:27 (+00:02)
// Run time: 52ms
// Memory: 1.65Mb
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long s = 0;
    vector<long long> as(n), bs(n);
    for (auto&& a : as) cin >> a;
    for (auto&& b : bs) cin >> b;

    for (int i = 0; i < n; i++)
        s += as[i] * bs[i];

    cout << s << endl;
}