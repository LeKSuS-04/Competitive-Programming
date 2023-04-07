/* UVa 11498 - Division of Nlogonia */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2493
// Date: 2021-01-16 06:27:58
// Run time: 0.000
// Verdict: AC

#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>

int main() {
    int k, cx, cy, x, y;

    while (scanf("%d", &k), k) {
        scanf("%d %d", &cx, &cy);

        while (k--) {
            scanf("%d %d", &x, &y);

            if (x == cx || y == cy) printf("divisa\n");
            else if (x > cx && y > cy) printf("NE\n");
            else if (x < cx && y > cy) printf("NO\n");
            else if (x > cx && y < cy) printf("SE\n");
            else if (x < cx && y < cy) printf("SO\n");
        }
    }
}