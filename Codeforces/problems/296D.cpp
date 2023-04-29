/* 296D. Egor and Graph */
// https://codeforces.com/problemset/problem/296/D
// Date: 	2023-04-13 21:08:19
// Run time: 2090 ms
// Memory: 2200 KB
// Verdict: AC

#ifndef LOCALENV
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
typedef pair<int, int> ii;
typedef vector<int> vi;

const int INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<vi> AM(n, vi(n));
    for (auto&& r : AM) {
        for (auto&& c : r) {
            cin >> c;
        }
    }
    vi x(n);
    for (auto&& xi : x) {
        cin >> xi;
        --xi;
    }
    reverse(x.begin(), x.end());

    vi answer;
    unordered_set<int> vs;
    for (int xi : x) {
        vs.insert(xi);

        for (int s = 0; s < n; s++) {
            for (int f = 0; f < n; f++) {
                AM[s][f] = min(AM[s][f], AM[s][xi] + AM[xi][f]);
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vs.count(i) == 1 && vs.count(j) == 1) {
                    sum += AM[i][j];
                }
            }
        }
        answer.push_back(sum);
    }

    reverse(answer.begin(), answer.end());
    for (int a : answer) {
        cout << a << ' ';
    }
    cout << '\n';
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