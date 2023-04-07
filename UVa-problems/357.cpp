/* UVa 357 - Let Me Count The Ways */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=293
// Date: 2021-09-06 18:26:47
// Runtime: 0.000
// Verdict: AC

#include <stdio.h>
#include <string.h>
using namespace std;

typedef long long ll;

int coins[] = {50, 25, 10, 5, 1};
ll memo[30010][5];

ll count(int left, int coin) {
    if (left == 0) return 1;
    if (memo[left][coin] != -1) return memo[left][coin];

    ll ans = 0;
    for (int i = coin; i < 5; i++) 
        if (left >= coins[i])
            ans += count(left - coins[i], i);

    return memo[left][coin] = ans;
}

int main() {
    memset(memo, -1, sizeof memo);
    int n;
    while (scanf("%d\n", &n) != EOF) {
        ll w = count(n, 0);
        if (w == 1) 
            printf("There is only 1 way to produce %d cents change.\n", n);
        else
            printf("There are %lld ways to produce %d cents change.\n", w, n);
    }
}