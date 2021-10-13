/* B. Charmed by the Game */
// https://codeforces.com/contest/1561/problem/B
// Date: Aug/24/2021 19:36 (02:01:49)
// Runtime: 31 ms
// Memory: 3652 KB
// Verdict: AC

#include <iostream>
#include <set>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int a, b, s;
        cin >> a >> b;
        s = a + b;

        if (s % 2 == 0) {
            cout << (s + 1 - abs(a - b)) / 2 + 1 << endl;
            for (int i = abs(a - b)/2; i <= s + 1 - abs(a - b)/2; i += 2) {
                cout << i << " ";
            }
            cout << endl;
        } else {
            cout << (s + 1 - abs(a - b)) + 1 << endl;
            for (int i = abs(a - b)/2; i < s + 1 - abs(a - b)/2; i++) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
}