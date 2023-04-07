/* UVa 10550 - Combination Lock */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1491
// Date: 2021-01-15 19:16:58
// Run time: 0.000
// Verdict: AC

#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int a, b, c, d;

    while (scanf("%d %d %d %d", &a, &b, &c, &d), (a || b || c || d)) {
        printf("%d\n", 720 + 9 * (b > a ? 40 - b + a : a - b)  + 360 + 9 * (c > b ? c - b : 40 - b + c) + 9 * (d > c ? 40 - d + c : c - d));
    }
}