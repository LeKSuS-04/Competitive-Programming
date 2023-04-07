/* UVa 11517 - Exact Change */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=2512&mosmsg=Submission+received+with+ID+26750338
// Date: 2021-09-07 04:59:31
// Runtime: 0.030
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

const int MAXVAL = 30001;
const int INF = 1e9;
int memo[MAXVAL];

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        memo[0] = 0;
        for (int i = 1; i < MAXVAL; i++) memo[i] = INF;

        int n, cost;
        cin >> cost >> n;
        vector<int> coins(n);
        for (int i = 0; i < n; i++) 
            cin >> coins[i];

        for (auto&& c : coins) 
            for (int i = MAXVAL - c - 1; i >= 0; i--) 
                if (memo[i] != INF)
                    memo[i + c] = min(memo[i + c], memo[i] + 1);
            
        for (int i = cost; i < MAXVAL; i++) 
            if (memo[i] != INF) {
                cout << i << " " << memo[i] << endl;
                break;
            }
    }
}