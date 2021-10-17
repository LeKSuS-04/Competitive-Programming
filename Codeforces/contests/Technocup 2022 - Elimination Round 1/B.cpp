/* B - Omkar and Heavenly Tree */
// https://codeforces.com/contest/1583/problem/B
// Date: Oct/17/2021 14:32 (00:27:57)
// Runtime: 670 ms
// Memory: 0 KB
// Verdict: AC

#include <bitset>
#include <iostream>
using namespace std;

const int MAX = 1e5 + 10;
bitset<MAX> can_be_central;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n >> m;
        
        can_be_central.set();
        while (m--) {
            int a, b, c;
            cin >> a >> b >> c;
            can_be_central[b - 1] = false;
        }

        for (int i = 0; i < n; i++) {
            if (can_be_central[i]) {
                for (int j = 0; j < n; j++) if (j != i)
                    cout << i + 1 << " " << j + 1 << endl;
                break;
            }
        }

        cout << endl;
    }
}