// Verdict: AC
// #ifndef LOCALENV
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
typedef pair<int, int> ii;
typedef vector<int> vi;

int n, m;
vector<int> ls;

bool can_fit(int w) {
    int s = 0;
    int line = 1;
    for (auto&& li : ls) {
        if (li > w) {
            return false;
        } else if (s + li <= w) {
            s += li + 1;
        } else {
            s = li + 1;
            line += 1;
            if (line > m) {
                return false;
            }
        }
    }
    return line <= m;
}

void solve() {
    cin >> n >> m;
    ls.resize(n);
    for (auto&& li : ls) cin >> li;

    int l = 0;
    int r = 4e18;
    while (r - l > 1) {
        int w = (r + l) / 2;
        if (can_fit(w)) {
            r = w;
        } else {
            l = w;
        }
    }

    if (can_fit(r)) {
        cout << r << endl;
    } else {
        cout << l << endl;
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