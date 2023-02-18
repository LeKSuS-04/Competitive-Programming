/* C - Coverage */
// https://atcoder.jp/contests/abc289/tasks/abc289_c
// Date: 2023-02-11 15:28:45
// Run time: 7 ms
// Memory: 3552 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
    #endif
    
    int n, m;
    cin >> n >> m;

    vector<set<int>> sets(m);
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int a;
            cin >> a;
            sets[i].insert(a);
        }
    }

    int total = 0;
    for (int i = 1; i < (1 << m); i++) {
        vector<char> contains(n, false);
        for (int k = 0; (1 << k) <= i && k < sets.size(); k++) {
            if (((1 << k) & i) == 0) continue;
            for (int j = 1; j <= n; j++) {
                contains[j-1] |= sets[k].find(j) != sets[k].end();
            }
        }
        if (all_of(contains.begin(), contains.end(), [](char c) { return c == true; })) {
            total += 1;
        }
    }

    cout << total << endl;
}