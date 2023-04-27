// Verdict: AC
#ifndef LOCALENV
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// #define int ll
typedef pair<int, int> ii;
typedef vector<int> vi;

void solve() {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;

    list<char> s;
    for (char c : str) {
        s.push_back(c);
    }
    {
        auto it = s.begin();
        int cnt = k;
        while (cnt != 0) {
            if (*it == '(') {
                it = s.erase(it);
                cnt--;
            } else {
                ++it;
            }
        }
    }
    {
        auto it = prev(s.end());
        int cnt = k;
        while (cnt != 0) {
            if (*it == ')') {
                it = prev(s.erase(it));
                cnt--;
            } else {
                --it;
            }
        }
    }

    int balance = 0;
    for (char c : s) {
        if (c == '(') ++balance;
        else --balance;
        if (balance < 0) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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