/* UVa 11718 - Fantasy of a Summation */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2765
// Date: 2021-09-11 13:24:09
// Runtime: 0.010
// Verdict: AC

#include <iostream>
using namespace std;

int MOD;
long long pow_mod(long long a, int k) {
    if (k == 0) return 1;
    if (k % 2 == 0) return pow_mod(a * a % MOD, k / 2);
    else return a * pow_mod(a, k - 1) % MOD;
}

int main() {
    int TC, case_n = 0;
    cin >> TC;
    while (TC--) {
        int n, k;
        cin >> n >> k  >> MOD;
        
        long long res = 0, t = pow_mod(n, k - 1);
        for (int i = 0; i < n; i++) {
            long long a;
            cin >> a;

            res = (((k * a % MOD) * t) % MOD + res) % MOD;
        }

        cout << "Case " << ++case_n << ": " << res << endl;
    }
}