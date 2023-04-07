/* 234C. Weather */
// https://codeforces.com/problemset/problem/234/C
// Date: ?
// Run time: 436 ms
// Memory: 1200 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
    
    freopen("input.txt", "r", stdin);    
    freopen("output.txt", "w", stdout);    
    
    int n;
    cin >> n;

    int z = 0;
    vector<int> pos_bef(n+1, 0);
    vector<int> neg_aft(n+1, 0);
    vector<int> t(n);
    for (auto&& ti : t) cin >> ti;

    for (int i = 0; i < n; i++) {
        z += (t[i] == 0);
    }

    if (t[0] > 0) {
        t[0] = -1;
        z += 1;
    }
    if (t[n - 1] < 0) {
        t[n - 1] = 1;
        z += 1;
    }

    for (int i = 1; i < n+1; i++) {
        if (t[i-1] > 0) pos_bef[i] += 1;
        pos_bef[i] += pos_bef[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        if (t[i] < 0) neg_aft[i] += 1;
        neg_aft[i] += neg_aft[i + 1];
    }

    int mini = n + 100;
    for (int i = 0; i < n+1; i++) {
        mini = min(mini, pos_bef[i] + neg_aft[i]);
    }

    cout << z + mini << endl;
}