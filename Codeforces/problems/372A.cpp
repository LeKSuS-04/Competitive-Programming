/* 372A. Counting Kangaroos is Fun */
// https://codeforces.com/contest/372/problem/A
// Date: 11/Sep/2022 17:53
// Run time: 639 ms
// Memory: 2000 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> s;

bool can_separate(int from) {
    for (int i = 0; from + i < n && i < from; i++)
        if (s[from + i] < 2 * s[i])
            return false;
    return true;
}

int main() {
    cin >> n;
    s.resize(n);
    for (auto&& si : s) cin >> si;

    sort(s.begin(), s.end());
    int l = n/2, r = n, m;

    while (r - l > 1) {
        m = (r + l) / 2;
        if (can_separate(m)) r = m;
        else l = m;
    }

    // I hate my life
    for (int i = max(l - 100, (n+1)/2); i < min(n, r + 100); i++)
        if (can_separate(i)) {
            cout << i << endl;
            return 0;
        }
    cout << n << endl;
}