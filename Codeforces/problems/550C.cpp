/* 550C. Divisibility by Eight */
// https://codeforces.com/problemset/problem/550/C
// Date: ?
// Run time: 15 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> n;
    for (int i = 0; i < s.size(); i++) {
        n.push_back(s[i] - '0');
    }

    int k;
    for (int a = 0; a < n.size(); a++) {
        for (int b = a + 1; b < n.size(); b++) {
            for (int c = b + 1; c < n.size(); c++) {
                k = 100*n[a] + 10*n[b] + n[c];
                if (k % 8 == 0) {
                    cout << "YES\n" << k << endl;
                    return 0;
                }
            }
        }
    }
    for (int a = 0; a < n.size(); a++) {
        for (int b = a + 1; b < n.size(); b++) {
            k = 10*n[a] + n[b];
            if (k % 8 == 0) {
                cout << "YES\n" << k << endl;
                return 0;
            }
        }
    }
    for (int a = 0; a < n.size(); a++) {
        k = n[a];
        if (k % 8 == 0) {
            cout << "YES\n" << k << endl;
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}