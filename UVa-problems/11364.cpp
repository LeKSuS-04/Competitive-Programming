/* UVa 11364 - Parking */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2349
// Date: 2021-01-16 06:18:06
// Run time: 0.000
// Verdict: AC

#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <climits>

int main() {
    int k, n;
    scanf("%d", &k);

    while (k--) {
        scanf("%d", &n);

        int min = INT_MAX, max = INT_MIN;
        for (int i = 0; i < n; i++) {
            int temp;
            scanf("%d", &temp);

            if (temp > max) max = temp;
            if (temp < min) min = temp;
        }

        printf("%d\n", 2 * (max - min));
    }
}