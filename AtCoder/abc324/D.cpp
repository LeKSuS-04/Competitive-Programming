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

const int MAX = 10'000'000'000'000LL;
vector<int> goal(10, 0);

vector<int> get_chars(int l) {
    vector<int> chars(10, 0);
    while (l != 0) {
        chars[l % 10]++;
        l /= 10;
    }
    return chars;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (const auto& c : s) {
        goal[c - '0'] += 1;
    }

    int answ = 0;
    for (int i = 0; i * i <= MAX; i++) {
        int square = i * i;
        vector<int> chars = get_chars(square);

        bool result = true;
        for (int i = 0; i < 10; i++) {
            if (chars[i] == goal[i]) {
                continue;
            }
            if (chars[i] < goal[i] && i == 0) {
                continue;
            }
            result = false;
            break;
        }

        if (result) {
            answ += 1;
        }
    }

    cout << answ;
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