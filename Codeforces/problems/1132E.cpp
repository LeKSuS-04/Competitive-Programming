/* 1132E. Knapsack */
// https://codeforces.com/problemset/problem/1132/E
// Date: 2022-11-04 12:10:53
// Run time: 31 ms
// Memory: 12 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const ull LCM = 3 * 5 * 7 * 8;
const ull DIV = LCM;
const ull N = DIV * 16;

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif

    ull w, cnti[9], free[9], packs = 0;
    cin >> w;
    for (ull i = 1; i <= 8; i++) {
        cin >> cnti[i];
        ull t = max(cnti[i] / (DIV / i), 1ULL) - 1;
        packs += t;
        free[i] = cnti[i] - t * (DIV / i);
    }

    vector<char> dp_prev(N, 0);
    vector<char> dp(N, 0);
    dp[0] = 1;
    for (ull i = 1; i <= 8; i++) {
        dp.swap(dp_prev);
        for (ull j = 0; j <= free[i]; j++) {
            for (ull k = i * j; k < N; k++) {
                dp[k] |= dp_prev[k - i * j];
            }
        }
    }

    ull max_weight = 0;
    for (ull i = 0; i < min(N, w + 1ULL); i++) {
        if (dp[i]) {
            max_weight = max(max_weight, min((w - i) / DIV, packs) * DIV + i);
        }
    }

    cout << max_weight << endl;
}