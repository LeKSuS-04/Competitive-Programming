/* D - Step Up Robot */
// https://atcoder.jp/contests/abc289/tasks/abc289_d
// Date: 2023-02-11 15:33:56
// Run time: 35 ms
// Memory: 3800 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
    #endif
    
    int n, m, x;
    cin >> n;
    vector<int> a(n);
    for (auto&& ai : a) cin >> ai;
    cin >> m;
    vector<int> b(m);
    for (auto&& bi : b) cin >> bi;
    cin >> x;

    vector<char> possible(x + 10, false);
    possible[0] = true;
    vector<char> has_trap(x + 10, false);
    for (auto&& bi : b) {
        has_trap[bi] = true;
    }

    for (int i = 0; i < possible.size(); i++) {
        if (possible[i]) {
            for (auto&& step : a) {
                if (i + step < possible.size() && !has_trap[i + step]) {
                    possible[i + step] = true;
                }
            }
        }
    }

    cout << (possible[x] ? "Yes" : "No") << endl;
}