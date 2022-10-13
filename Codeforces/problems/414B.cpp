/* 414B. Mashmokh and ACM */
// https://codeforces.com/problemset/problem/414/B
// Date: ?
// Run time: 264 ms
// Memory: 32000 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const ll MAX = 2010;

ll memo[MAX][MAX];
vector<vector<int>> divs;

ll find_answer(int n, int k) {
    if (memo[n][k] != -1) return memo[n][k];
    if (n == 1 || k <= 1) return 1;

    ll answ = 0;
    for (auto d : divs[n]) {
        answ = (answ + find_answer(d, k-1)) % MOD;
    }
    return (memo[n][k] = answ);
}

int main() {
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < MAX; i++)
    for (int j = 0; j < MAX; j++)
        memo[i][j] = -1;

    divs.resize(MAX);
    for (int i = 1; i < MAX; i++) {
        for (int j = 1; j*j <= i; j++) {
            if (i % j == 0) {
                divs[i].push_back(j);
                if (j*j != i) divs[i].push_back(i / j);
            }
        }
    }

    ll answ = 0;
    for (int i = 1; i <= n; i++)
        answ = (answ + find_answer(i, k)) % MOD;
    cout << answ << endl;
}