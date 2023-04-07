/* UVa 11526 - H(n) */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2521
// Date: 2021-09-11 17:35:19
// Runtime: 0.040
// Verdict: AC

#include <iostream>
#include <math.h>
using namespace std;

long long H(int n){
    if (n <= 0) return 0;

    long long res = n, a = n, b, sq = sqrt(n);
    for (int i = 2; i <= sq; i++) {
        b = a, a = n/i;
        res += a + (b - a) * (i - 1);
    }
    res += (a - sq) * sq;
    return res;
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        cout << H(n) << endl;
    }
}