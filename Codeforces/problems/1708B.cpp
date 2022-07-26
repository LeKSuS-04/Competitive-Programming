/* 1708B. Difference of GCDs  */
// https://codeforces.com/contest/1708/problem/B
// Date: Jul/26/2022 12:39
// Run time: 109 ms
// Memory: 1100 KB
// Verdict: AC
#include <bits/stdc++.h>
using namespace std;

int main() {
    int TC; cin >> TC;
    while (TC--) {
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> answ;
        answ.push_back(l);
        for (int i = 2; i <= n; i++) {
            int x = l + (i - l % i) % i;
            if (x > r) break;
            answ.push_back(x);
        }

        if (answ.size() == n) {
            cout << "YES\n";
            for (auto a : answ)
                cout << a << " ";
            cout << "\n";
        } else cout << "NO\n";
    }
}