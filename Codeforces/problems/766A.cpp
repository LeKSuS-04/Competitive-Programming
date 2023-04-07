/* 766A. Mahmoud and Longest Uncommon Subsequence */
// https://codeforces.com/problemset/problem/766/A
// Date: 2022-11-11 19:12:51
// Run time: 31 ms
// Memory: 348 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    if (a.size() != b.size()) {
        cout << max(a.size(), b.size()) << endl;
    } else if (a == b) {
        cout << -1 << endl;
    } else {
        cout << a.size() << endl;
    }
}