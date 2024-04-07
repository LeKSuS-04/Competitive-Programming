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

map<char, ii> direction = {
    {'U', {-1, 0}},
    {'D', {1, 0}},
    {'L', {0, -1}},
    {'R', {0, 1}},
};

bool try_walk(const string& path, const vector<string>& mp, int i, int j) {
    if (mp[i][j] == '#') {
        return false;
    }

    for (char c : path) {
        auto d = direction[c];
        i += d.first;
        j += d.second;
        if (mp[i][j] == '#') {
            return false;
        }
    }

    return true;
}

void solve() {
    int h, w, n;
    cin >> h >> w >> n;
    string t;
    cin >> t;
    vector<string> s(h);
    for (auto&& si : s) {
        cin >> si;
    }

    int c = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (try_walk(t, s, i, j)) {
                c += 1;
            }
        }
    }
    cout << c << endl;
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