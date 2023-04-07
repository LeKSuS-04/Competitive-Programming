/* UVa 10212 - The Last Non-zero Digit. */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1153
// Date: 2021-09-23 16:27:50
// Runtime: 1.250
// Verdict: AC

#include <iostream>
using namespace std;

typedef long long ll;

int mult_range_ld(int l, int r) {
    ll ans = 1;
    for (int i = l; i <= r; i++) {
        ans = ans * i;
        while (ans % 10 == 0) ans /= 10;
        ans %= 100000000000LL;
    }
    return ans % 10;
}

int main() {
    int n, m;
    while (cin >> n >> m) 
        cout << mult_range_ld(n - m + 1, n) << endl;
}