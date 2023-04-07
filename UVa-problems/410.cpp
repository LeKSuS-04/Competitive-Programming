/* UVa 410 - Station Balance */ 
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=657&page=show_problem&problem=351
// Date: 2021-08-09 08:27:49
// Run time: 0.010
// Verdict: AC

#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

int main() {
    int c, s, t = 1;
    double av, diff;
    vector<int> m;

    while (scanf("%d %d", &c, &s) != EOF) {
        m.assign(c * 2, 0);
        av = diff = 0;
        for (int i = 0; i < s; i++) scanf("%d", &m[i]), av += m[i];
        av /= c;
        sort(m.begin(), m.end());

        printf("Set #%d\n", t++);
        for (int i = 0; i < c; i++) {
            diff += abs(av - (m[i] + m[c*2 - 1 - i]));
            printf("%2d:", i);
            if (m[c*2 - 1 - i]) printf(" %d", m[c*2 - 1 - i]);
            if (m[i]) printf(" %d", m[i]);
            printf("\n");
        }
        printf("IMBALANCE = %.5f\n\n", diff);
    }
}