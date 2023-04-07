/* A. Balanced Substring */
// https://codeforces.com/problemset/problem/1569/A
// Date: 08.09.2021 18:17
// Runtime: 15ms
// Memory: 3600 KB
// Verdict: AC

#include <iostream>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        string s;
        cin >> n >> s;

        bool found = false;
        for (int i = 1; i < n && !found; i++) {
            if (s[i - 1] != s[i]) {
                found = true;
                cout << i << " " << i + 1 << endl;
            }
        }
        if (!found) cout << "-1 -1\n";
    }
}