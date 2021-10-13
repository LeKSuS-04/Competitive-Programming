/* UVa 11137 - Ingenuous Cubrency */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2078
// Date: 2021-09-07 15:38:50
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

typedef long long ll;

vector<int> coins;
void fill_coins() {
    coins.clear();
    for (int i = 1; i <= 21; i++)
        coins.push_back(i * i * i);
}

ll memo[10005][25];
ll count(int left, int coin) {
    if (left == 0) return 1;
    if (memo[left][coin] != -1) return memo[left][coin];

    ll ans = 0;
    for (int i = coin; i < coins.size(); i++) 
        if (coins[i] <= left) ans += count(left - coins[i], i);

    return memo[left][coin] = ans;
}
 
int main() {
    fill_coins();
    memset(memo, -1, sizeof memo);

    int n;
    while (cin >> n) 
        cout << count(n, 0) << endl;
}