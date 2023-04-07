/* UVa 10773 - Back to Intermediate Math */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1714
// Date: 2021-09-11 11:07:40
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main() {
    int TC, case_n = 0;
    cin >> TC;
    while (TC--) {
        float d, v, u;
        cin >> d >> v >> u;

        if(u > v && v > 0) 
            printf("Case %d: %.3f\n", ++case_n, d/sqrt(u*u - v*v) - d/u);
        else
            printf("Case %d: can't determine\n", ++case_n);
    }
}