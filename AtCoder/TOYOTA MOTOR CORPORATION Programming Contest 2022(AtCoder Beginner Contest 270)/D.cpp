/* D - Stones */
// https://atcoder.jp/contests/abc270/tasks/abc270_b
// Date: 2022-09-24 15:32:27
// Run time: 8 ms
// Memory: 3668 KB	
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (auto&& ai : a) cin >> ai;

    sort(a.begin(), a.end());
    
    vector<int> memo(n+1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (a[j] <= i) {
                memo[i] = max(memo[i], a[j] + (i-a[j] - memo[i-a[j]]));
            }
        }
    }

    cout << memo[n];
}