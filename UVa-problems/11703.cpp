/* UVa 11703 - sqrt log sin */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2750
// Date: 2021-08-07 14:50:22
// Run time: 0.080
// Verdict: AC

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int memo[1000010];

int get_x(int i) {
    if (memo[i]) return memo[i];
    else {
        int x = (get_x(floor(i - sqrt(i))) % 1000000 +
                 get_x(floor(log(i))) % 1000000 +
                 get_x(floor(i * pow(sin(i), 2))) % 1000000) % 1000000;
        return memo[i] = x;
    }
}

int main() {
    int n;

    memset(memo, 0, sizeof memo);
    memo[0] = 1;

    while (cin >> n, n != -1) cout << get_x(n) << endl;
}