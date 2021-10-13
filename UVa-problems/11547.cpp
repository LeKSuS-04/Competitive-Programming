/* UVa 11547 - Automatic Answer */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2542
// Date: 2021-01-19 11:18:22
// Run time: 0.000
// Verdict: AC

#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cmath>

// Multiply n by 567, then divide the result by 9, then add 7492, then multiply by 235, then divide
// by 47, then subtract 498. What is the digit in the tens column ?

int main() {
    int n, k;
    scanf("%d", &k);

    while (k--) {
        scanf("%d", &n);
        printf("%d\n", abs(((( n * 567 / 9 + 7492) * 235 / 47 - 498) % 100) / 10));
    }
}
