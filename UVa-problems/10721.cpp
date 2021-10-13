/* UVa 10721 - Bar Codes */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1662
// Date: 2021-09-07 17:56:49
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <string.h>
using namespace std;

typedef long long ll;
ll memo[55][55];

int m;
ll count(int n, int k) {
    if (n > k * m || n < k) return 0;
    if (k == 1) return 1;
    if (memo[n][k] != -1) return memo[n][k];

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        if (n - i >= 0) 
            ans += count(n - i, k - 1);
    }
    return memo[n][k] = ans;
}

int main() {
    int n, k;
    while (cin >> n >> k >> m) {
        memset(memo, -1, sizeof memo);
        cout << count(n, k) << endl;
    }
}