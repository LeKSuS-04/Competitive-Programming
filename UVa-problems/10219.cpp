/* UVa 10219 - Find the ways! */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1160
// Date: 2021-09-16 16:25:43
// Runtime: 0.000 
// Verdict: AC

#include <iostream>
#include <limits.h>
#include <math.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, k;
    while (cin >> n >> k) {    
        long double ans = 0;

        k = min(k, n - k);
        for (ll i = n - k + 1; i <= n; i++) ans += log10(i);
        for (ll i = 2; i <= k; i++) ans -= log10(i);
        cout << (ll) floor(ans) + 1 << endl;
    }
}