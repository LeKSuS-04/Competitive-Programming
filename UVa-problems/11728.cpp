/* UVa 11728 - Alternate Task */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2828
// Date: 2021-09-23 15:58:59
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

const int MAX = 1010;
int sums[MAX];
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

int sum_div(int n) {
    int ans = 1, pf_idx = 0, pf = primes[pf_idx];

    while (pf * pf <= n) {
        int next_pwr = pf, total = 1;
        while (n % pf == 0) {
            total += next_pwr;
            next_pwr *= pf;
            n /= pf;
        }
        ans *= total;
        pf = primes[++pf_idx];
    }
    if (n != 1) ans *= (n + 1);
    return ans;
}

int main() {
    memset(sums, -1, sizeof sums);
    for (int i = 1; i < MAX; i++) {
        int res = sum_div(i);
        if (res < MAX) sums[res] = i;
    }

    int n, case_n = 0;
    while (cin >> n, n) 
        cout << "Case " << ++case_n << ": " << sums[n] << endl;
}