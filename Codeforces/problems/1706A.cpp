/* 1706A. Another String Minimization Problem */
// https://codeforces.com/contest/1706/problem/A
// Date: Jul/25/2022 10:53
// Run time: 93 ms
// Memory: 0 KB
// Verdict: AC

#include <iostream>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, m, a1, a2;
        cin >> n >> m;
        string s(m, 'B');
        while (n--) {
            cin >> a1; a1--;
            a2 = m - 1 - a1;
            if (s[min(a1, a2)] == 'B')
                s[min(a1, a2)] = 'A';
            else
                s[max(a1, a2)] = 'A';
        }
        cout << s << endl;
    }
}