/* 1288A. Deadline */
// https://codeforces.com/problemset/problem/1288/A
// Date: 2022-10-19 19:43:39
// Run time: 15 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

int n, d;
ld f(ld x) { return x + ceill((long double)d / (x + 1)); }
int f(int x) { return x + (d + x) / (x + 1); }

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        cin >> n >> d;

        ld l = 0, r = n + 1;
        ld m1, m2;
        while (r - l > 1) {
            m1 = l + (r - l) / 3;
            m2 = r - (r - l) / 3;
            if (f(m1) > f(m2)) l = m1;
            else r = m2;
        }

        for (int x = max(0, (int)l - 100); x < min((int)r + 100, (int)n); x++) {
            if (f(x) <= n) {
                cout << "YES";
                goto end_loop;
            }
        }
        cout << "NO";
    end_loop:
        cout << endl;
    }
}