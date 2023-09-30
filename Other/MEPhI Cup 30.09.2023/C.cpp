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

void solve() {
    int n;
    cin >> n;

    vector<vi> f;
    for (int i = 0; i < n; i++) {
        f.push_back(vi());
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            f.back().push_back(x);
        }
    }

    std::vector<int> k;
    for (int i = 0; i < n; i++) {
        k.push_back(i);
    }

    int mx = 0;
    do {
        int m = 0;
        for (int i = 0; i < n; i++) {
            m += f[i][k[i]];
        }
        mx = max(m, mx);
    } while (next_permutation(k.begin(), k.end()));

    cout << mx << endl;
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