// Verdict: ?

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
typedef pair<int, int> ii;
typedef vector<int> vi;

int n, x, y, q;
vector<int> p, t;
vector<vector<int>> memo;
const int MOD = 840;

int query(int s, int i = 0) {
    if (i == n - 1) {
        return s % MOD;
    }

    int m = s % MOD;
    if (memo[m][i] != -1) {
        return memo[m][i];
    }

    memo[m][i] = query(s + (p[i] - s % p[i]) % p[i] + t[i], i + 1);
    return memo[m][i];
}

void solve() {
    cin >> n >> x >> y;
    p.resize(n - 1);
    t.resize(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> p[i];
        cin >> t[i];
    }

    memo.resize(MOD);
    for (auto&& memi : memo) {
        memi.assign(1e5 + 20, -1);
    }

    cin >> q;
    while (q--) {
        int qi;
        cin >> qi;

        int start = qi + x;
        cout << (start / MOD * MOD) + query(start) + y << '\n';
    }
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