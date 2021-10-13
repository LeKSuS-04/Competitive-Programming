/* UVa 10819 - Trouble of 13-Dots */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1760
// Date: 2021-10-05 06:45:19
// Runtime: 0.200
// Verdict: AC

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

const int INF = 1e9;
int n, m;
int memo[105][10210];
vector<int> w, v;

int dp(int idx, int used) {
    if (used > m + 200) return -INF;
    if (idx >= w.size()) {
        if (used > 2000) used -= 200;

        if (used > m) return -INF;
        else return 0;
    }
    if (memo[idx][used] != -1) return memo[idx][used];

    int ans = max(dp(idx + 1, used), v[idx] + dp(idx + 1, used + w[idx]));
    return (memo[idx][used] = ans);
}

int main() {
    while (cin >> m >> n) {
        memset(memo, -1, sizeof memo);

        w.resize(n);
        v.resize(n);
        for (int i = 0; i < w.size(); i++) 
            cin >> w[i] >> v[i];

        cout << dp(0, 0) << endl;
    }
}