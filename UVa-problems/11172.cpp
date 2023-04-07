/* UVa 11172 - Relational Operator */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2113
// Date: 2021-01-16 05:52:31
// Run time: 0.000
// Verdict: AC

#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>

int main() {
    int k, a, b;
    scanf("%d", &k);

    while (k--) {
        scanf("%d %d", &a, &b);

        if (a == b) printf("=\n");
        else if (a > b) printf(">\n");
        else printf("<\n");
    }
}