/* UVa 10943 - How do you add? */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1884
// Date: 2021-09-07 16:35:28
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <string.h>
using namespace std;

const int MOD = 1e6;
int memo[105][105];

int count(int n, int k) {
    if (k == 1) return 1;
    if (memo[n][k] != -1) return memo[n][k];

    memo[n][k] = 0;
    for (int i = 0; i <= n; i++) {
        memo[n][k] += count(n - i, k - 1);
        memo[n][k] %= MOD;
    }
    return memo[n][k];
}

int main() {
    memset(memo, -1, sizeof memo);

    int n, k;
    while (cin >> n >> k, n | k) 
        cout << count(n, k) << endl;
}