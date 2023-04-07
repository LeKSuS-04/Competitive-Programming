/* UVa 573 - The Snail */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=514
// Date: 2021-02-05 13:01:30
// Run time: 0.000
// Verdict: AC

#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
using namespace std;

int main() {
    float h, u, d, f;

    while (scanf("%f %f %f %f", &h, &u, &d, &f), h) {
        int day = 0;
        float height = 0, fatigue = u * f / 100;

        while (height >= 0) {
            day++;
            height += u;
            u -= fatigue;
            if (u < 0) u = 0;

            if (height > h) break;
            else height -= d;
        }

        if (height < 0) printf("failure on day %d\n", day);
        else printf("success on day %d\n", day);
    }
}