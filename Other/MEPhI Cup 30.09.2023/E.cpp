// Verdict: AC
// #ifndef LOCALENV
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// #define int ll
typedef pair<int, int> ii;
typedef vector<int> vi;

int n, k;
const int M = 1e9 + 7;
const int LIM = 1005;
int memo[LIM][LIM];

int solve(int i, int j) {
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    int a = i - 1 < 0 ? 0 : solve(i - 1, j);
    int b = i - 2 < 0 ? 0 : solve(i - 2, j);
    int c = i + 1 > n ? 0 : (j == 0 ? 0 : solve(i + 1, j - 1));
    int d = i + 2 > n ? 0 : (j == 0 ? 0 : solve(i + 2, j - 1));

    return (memo[i][j] = (((a + b) % M + c) % M + d) % M);
}

void solve() {
    cin >> n >> k;

    for (int i = 0; i < LIM; i++) {
        for (int j = 0; j < LIM; j++) {
            memo[i][j] = -1;
        }
    }

    for (int j = 0; j < LIM; j++) {
        memo[0][j] = 1;
    }

    cout << solve(n, k) << endl;
}

signed main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC = 1;
    // cin >> TC;
    while (TC--) {
        solve();
    }
    cout.flush();
}