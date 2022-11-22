/* 340D. Bubble Sort Graph */
// https://codeforces.com/problemset/problem/340/D
// Date: 2022-11-11 19:22:11
// Run time: 248 ms
// Memory: 1412 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> lis;
    for (auto&& ai : a) cin >> ai;

    for (auto&& ai : a) {
        if (lis.size() == 0) {
            lis.push_back(ai);
            continue;
        }
        if (ai > lis.back()) {
            lis.push_back(ai);
            continue;
        }

        auto it = lower_bound(lis.begin(), lis.end(), ai);
        *it = ai;
    }

    cout << lis.size() << endl;
}