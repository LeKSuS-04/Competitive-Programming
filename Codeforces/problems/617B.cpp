/* 617B. Chocolate */
// https://codeforces.com/problemset/problem/617/B
// Date: 2022-10-28 09:33:48
// Run time: 15 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    #ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
    #endif
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& ai : a) cin >> ai;

    ull answ = 1;
    int prev = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            if(prev != -1) answ *= (i - prev);
            prev = i;
        }
    }

    if (prev == -1) cout << 0 << endl;
    else cout << answ << endl;
}