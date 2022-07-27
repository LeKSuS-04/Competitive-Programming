/* 1705B. Mark the Dust Sweeper  */
// https://codeforces.com/contest/1705/problem/B
// Date: Jul/27/2022 10:55
// Run time: 358 ms
// Memory: 1600 KB
// Verdict: 

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int TC; cin >> TC;
    while (TC--) {
        int n;
        cin >> n;

        vector<ll> a(n);
        for (auto&& ai : a)
            cin >> ai;
        
        ll sum = 0;
        bool met_value = false;
        for (int i = 0; i < n - 1; i++){
            if (a[i] == 0) sum += met_value;
            else sum += a[i];
            met_value |= a[i] != 0;
        }

        cout << sum << endl;
    }
}