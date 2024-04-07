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

map<char, pair<int, int>> direction = {
    {'U', {0, 1}},
    {'R', {1, 0}},
    {'D', {0, -1}},
    {'L', {-1, 0}}
};

void solve() {
    int n, q;
    cin >> n >> q;
    deque<pair<int, int>> c;
    for (int i = 0; i < n; i++) {
        c.push_front({i + 1, 0});
    }

    while (q--) {
        int cmd; 
        cin >> cmd;

        if (cmd == 1) {
            char d;
            cin >> d;
            auto coords = c.back();
            c.pop_front();
            c.push_back({coords.first + direction[d].first, coords.second + direction[d].second});
        } else {
            int p;
            cin >> p;
            cout << c[n - p].first << ' ' << c[n - p].second << '\n';
        }
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