/* 1040A. Palindrome Dance */
// https://codeforces.com/contest/1040/problem/A
// Date: Sep/11/2022 18:21
// Run time: 15 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> c(n);
    for (auto&& ci : c) cin >> ci;

    int s = 0;
    for (int i = 0; i < (n+1)/2; i++) {
        if (c[i] == 2 && c[n - i - 1] != 2) s += (c[n - i - 1] == 0 ? a : b);
        else if (c[i] != 2 && c[n - i - 1] == 2) s += (c[i] == 0 ? a : b);
        else if (c[i] == c[n - i - 1] && c[i] == 2 && i != n - i - 1) s += 2 * min(a, b);
        else if (c[i] == c[n - i - 1] && c[i] == 2 && i == n - i - 1) s += min(a, b);
        else if (c[i] != c[n - i - 1]) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << s << endl;
}