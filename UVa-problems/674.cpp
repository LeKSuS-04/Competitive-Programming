/* 674 - Coin Change */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=615
// Date: 2021-07-30 17:08:36
// Run time: 0.060
// Verdict: AC

#include <iostream>
#include <string.h>
using namespace std;

int n, s, coins[] = { 50, 25, 10, 5, 1 };
int memo[5][8000];

int count(int coin_idx, int money) {
    if (money == 0) return 1;

    if (memo[coin_idx][money] != -1) return memo[coin_idx][money];

    int ans = 0;
    for (int i = coin_idx; i < 5; i++) {
        if (money >= coins[i]) {
            ans += count(i, money - coins[i]);
        }
    }
    return memo[coin_idx][money] = ans;
}

int main() {
    memset(memo, -1, sizeof memo);
    while (cin >> n) {
        cout << count(0, n) << endl;
    }
}