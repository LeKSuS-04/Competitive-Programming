/* 556A. Case of the Zeros and Ones */
// https://codeforces.com/problemset/problem/556/A
// Date: Sep/11/2022 10:25
// Run time: 46 ms
// Memory: 500 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int ones = 0, zeros = 0;
    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; i++)
        if (s[i] == '0') ++zeros;
        else ++ones;

    cout << n - 2 * min(zeros, ones) << endl;
}