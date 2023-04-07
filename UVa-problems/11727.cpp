/* UVa 11727 - Cost Cutting */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2827
// Date: 2021-01-19 11:24:59
// Run time: 0.000
// Verdict: AC

#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>

int main() {
    int k, a, b, c;
    scanf("%d", &k);

    for(size_t i = 1; i < k + 1; i++) {
        scanf("%d %d %d", &a, &b, &c);

        int n;
        if ((a >= b && b >= c) || (a <= b && b <= c)) n = b;
        else if ((b >= a && a >= c) || (b <= a && a <= c)) n = a;
        else n = c;

        printf("Case %d: %d\n", i, n);
    }
}