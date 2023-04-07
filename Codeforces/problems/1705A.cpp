/* 1705A. Mark the Photographer */
// https://codeforces.com/contest/1705/problem/A
// Date: Jul/27/2022 10:37
// Run time: 31 ms
// Memory: 100 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int TC; cin >> TC;
    while (TC--) {
        int n, x;
        cin >> n >> x;

        vector<int> h(2*n);
        for (auto&& hi : h)
            cin >> hi;

        sort(h.begin(), h.end());
        bool can_arrange = true;
        for (int i = 0; i < n && can_arrange; i++) 
            can_arrange &= h[n + i] - h[i] >= x;
        

        cout << (can_arrange ? "YES\n" : "NO\n");
    }
}