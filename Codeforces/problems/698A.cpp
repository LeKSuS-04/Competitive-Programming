/* 698A. Vacations */
// https://codeforces.com/problemset/problem/698/A
// Date: ?
// Run time: 15 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& ai : a)
        cin >> ai;

    vector<pair<int, int>> memo(n);
    if (a[0] == 0) memo[0] = {0, 0};
    if (a[0] == 1) memo[0] = {1, 1};
    if (a[0] == 2) memo[0] = {1, 2};
    if (a[0] == 3) memo[0] = {1, 0};

    for (int i = 1; i < n; i++) {
        auto prev = memo[i-1];
        if (a[i] == 0) memo[i] = {prev.first, 0};
        else if (a[i] == 3) memo[i] = {prev.first + 1, (3 - prev.second) % 3};
        else if (a[i] == prev.second) memo[i] = {prev.first, 0};
        else if (a[i] != prev.second) memo[i] = {prev.first + 1, a[i]};
    }

    cout << n - memo[n-1].first << endl;
}
