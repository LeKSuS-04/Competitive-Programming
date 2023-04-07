/* UVa 10616 - Divisible Group Sums */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1557
// Date: 2021-10-05 04:53:15
// Runtime: 0.010
// Verdict: AC

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
typedef long long ll;

int d, m;
vector<ll> v;
ll mod (ll a) { return (a % d + d) % d; }

int dp[205][25][15];
ll amount(int idx, int mod_d, int left) {
    if (dp[idx][mod_d][left] != -1) return dp[idx][mod_d][left];
    if (left == 0) return mod_d == 0;
    if (idx >= v.size()) return 0;

    ll ans = amount(idx + 1, mod_d, left) + amount(idx + 1, mod(mod_d + v[idx]), left - 1);
    return (dp[idx][mod_d][left] = ans);
}

int main() {
    int n, q, case_n = 0;
    while (cin >> n >> q, n | q) {

        v.resize(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        cout << "SET " << ++case_n << ":\n";
        for (int i = 1; i <= q; i++) {
            cin >> d >> m;

            memset(dp, -1, sizeof dp);
            cout << "QUERY " << i << ": " << amount(0, 0, m) << endl;
        }
    }
}