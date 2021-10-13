/* UVa 10306 - e-Coins */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1247
// Date: 2021-07-30 18:02:58
// Run time: 0.120
// Verdict: AC

#include <iostream>
#include <math.h>
#include <string.h>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

const int limit = 1e9;
int m, s;
vii coins;
int memo[610][610][50];

int sqrt(int x) { return (int) sqrt((double) x); }
bool is_sqrt(int x) { 
    int sq = sqrt(x);
    return (sq * sq == x);
}


int change(int x, int y, int coin_idx) {
    int emod = x * x + y * y;

    if (is_sqrt(emod) && sqrt(emod) == s) return 0;
    if (sqrt(emod) > s) return limit;

    if (memo[x][y][coin_idx] != -1) return memo[x][y][coin_idx];
    
    int ans = limit;
    for (int i = coin_idx; i < coins.size(); i++) {
        ans = min(ans, 1 + change(x + coins[i].first, y + coins[i].second, i));
    }

    return memo[x][y][coin_idx] = ans;
}


int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        memset(memo, -1, sizeof memo);

        cin >> m >> s;
        coins = vii(m);
        for (int i = 0; i < m; i++) cin >> coins[i].first >> coins[i].second;

        int ans = change(0, 0, 0);
        if (ans >= limit) cout << "not possible\n";
        else              cout << ans << "\n";
    }
}