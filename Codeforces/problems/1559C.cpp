/* 1559C - Mocha and Hiking */
// https://codeforces.com/contest/1559/problem/C
// Date: 23.08.2021 16:10
// Runtime: 31 ms
// Memory: 3700 KB
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        if (a[0] != 0) {
            cout << n + 1;
            for (int i = 0; i < n; i++) cout << " " << i + 1;
            cout << endl;
        } else if (n == 1) {
            cout << "1 2\n";
        } else if (a[a.size() - 1] == 0) {
            for (int i = 0; i < n; i++) cout << i + 1 << " ";
            cout << n + 1 << endl;
        } else {
            bool found = false;
            for (int i = 1; i < n && !found; i++) {
                if (a[i - 1] == 0 && a[i] != 0) {
                    found = true;

                    for (int j = 0; j < i - 1; j++) cout << j + 1 << " ";
                    cout << i << " " << n + 1 << " " << i + 1;
                    for (int j = i + 1; j < n; j++) cout << " " << j + 1;
                    cout << endl;
                }
            }

            if (!found) cout << "-1\n";
        }
    }
}