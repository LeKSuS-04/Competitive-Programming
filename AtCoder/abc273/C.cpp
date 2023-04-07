/* C. (K+1)-th Largest Number */
// https://atcoder.jp/contests/abc273/tasks/abc273_c
// Date: 2022-10-15 15:16:47
// Run time: 565 ms	
// Memory: 23596 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& ai : a) cin >> ai;

    unordered_map<int, int> cntr;
    for (auto&& ai : a) {
        if (cntr.find(ai) == cntr.end()) {
            cntr[ai] = 1;
        } else {
            cntr[ai] += 1;
        }
    }

    set<int> s;
    for (auto&& ai : a)
        s.insert(ai);

    vector<int> uq;
    for (auto&& si : s) {
        uq.push_back(si);
    }

    for (int k = 0; k < n; k++) {
        if (k > uq.size()) {
            cout << 0 << endl;
        } else {
            cout << cntr[uq[uq.size() - k - 1]] << endl;
        }
    }
}