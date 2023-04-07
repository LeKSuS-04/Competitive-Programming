/* 1806B. Mex Master */
// https://codeforces.com/contest/1806/problem/B
// Date: 2023-03-18 15:33:05
// Run time: 202 ms
// Memory: 768 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

const int MAX_A = 2e5 + 100;

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto&& ai : a) cin >> ai;

        int count_zero = 0, count_ones = 0;
        for (auto&& ai : a) {
            if (ai == 0) count_zero++;
            if (ai == 1) count_ones++;
        }

        if (count_zero <= (a.size() + 1) / 2) {
            cout << 0 << endl;
        } else if (count_ones != 0 && count_ones + count_zero == n) {
            cout << 2 << endl;
        } else {
            cout << 1 << endl;
        }
    }
}