/* UVa 374 - Big Mod */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=310
// Date: 2021-09-23 16:04:03
// Runtime: 0.000
// Verdict: AC

#include <iostream>
using namespace std;

typedef long long ll;
int mod;

ll pow_mod(ll b, ll p) {
    if (p == 0) return 1;
    if (p & 1) return b * pow_mod(b, p - 1) % mod;
    return pow_mod(b * b % mod, p/2);
}

int main() {
    ll b, p;
    while (cin >> b >> p >> mod)
        cout << pow_mod(b, p) << endl;
}