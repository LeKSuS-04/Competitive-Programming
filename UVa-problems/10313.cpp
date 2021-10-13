/* UVa 10313 - Pay the Price */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1254
// Date: 2021-10-07 19:13:10
// Runtime: 0.080
// Verdict: AC

#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;
typedef long long ll;

const int MAX = 305;
ll memo[MAX][MAX];

ll query(int n, int from, int to) {
    if (n == 0) return from == 0;
    
    from = max(from, 1);
    to = min(to, 300);

    if (from > to) return 0;
    else return memo[n][to] - memo[n][from - 1];
}

int main() {
    memset(memo, 0, sizeof memo);
    memo[0][0] = 1;
    for (int i = 1; i < MAX; i++) 
        for (int j = 1; j < MAX; j++) 
            for (int k = 1; i - k - (k - 1) * (j - 1) >= j - 1; k++) 
                memo[i][j] += memo[i - k - (k - 1) * (j - 1)][j - 1];

    for (int i = 0; i < MAX; i++)
        for (int j = 1; j < MAX; j++)
            memo[i][j] += memo[i][j - 1];
    
    string s;
    while (getline(cin, s)) {
        istringstream sin(s);
        int n, l1, l2;
        ll ans = 0;

        sin >> n;
        if (!(sin >> l1)) ans = query(n, 0, 300);
        else if (!(sin >> l2)) ans = query(n, 0, l1);
        else ans = query(n, l1, l2);
        cout << ans << endl;
    }
}