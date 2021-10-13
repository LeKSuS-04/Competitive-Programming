/* A - Countdown */
// https://codeforces.com/contest/1573/problem/A
// Date: Sep/18/2021 17:40 (00:05:05)
// Runtime: 15 ms
// Memory: 3648 KB
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

        int t = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                t += s[i] - '0';
                if (i != n - 1) t++;
            }
        }

        cout << t << endl;
    }
}