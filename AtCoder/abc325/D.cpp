// Verdict: WA
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

void solve() {
    int n;
    cin >> n;
    vector<ii> times;
    for (int i = 0; i < n; i++) {
        int t, d;
        cin >> t >> d;
        times.push_back({t, t + d});
    }

    set<ii> line;
    const int START = 0;
    const int END = 1;
    for (const auto&[st, et] : times) {
        line.insert({st, START});
        line.insert({st, END});
    }

    cout << count << endl;
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