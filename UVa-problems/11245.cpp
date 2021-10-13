/* UVa 11254 - Consecutive Integers */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2221
// Date: 2021-09-11 12:05:58
// Runtime: 0.020
// Verdict: AC

#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

long long sum(int l, int r) {
    return (long long) (r + l) * (r - l + 1) / 2;
}

int main() {
    int n;
    while (scanf("%d", &n), n != -1) {
        for (int i = sqrt(2*n); i > 0; i--) {
            int m = n/i;
            int l = (m - i/2 + (i + 1)%2), r = (m + i/2);

            if (sum(l, r) == n) {
                printf("%d = %d + ... + %d\n", n, l, r, i);
                break;
            }
        }
        
    }
}