/* 1674B. Dictionary */
// https://codeforces.com/problemset/problem/1674/B
// Date: 2022-10-28 09:25:02
// Run time: 0 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
    #endif
    
    int TC;
    cin >> TC;
    while (TC--) {
        string s;
        cin >> s;
        cout << (s[0] - 'a') * 25 + s[1] - 'a' - (s[0] < s[1]) + 1 << endl;
    }
}