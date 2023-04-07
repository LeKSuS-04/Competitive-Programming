/* UVa 10931 - Parity */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1872
// Date: 2021-09-11 17:04:11
// Runtime: 0.000
// Verdict: AC

#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n, n) {
        int mask = (1 << 30), p = 0;
        bool lead_zeros = true;

        cout << "The parity of ";
        while (mask) {
            if (n & mask) {
                p += 1;
                lead_zeros = false;
            }

            if (!lead_zeros) cout << bool(n & mask);
            mask >>= 1;
        }
        cout << " is " << p << " (mod 2).\n";
    }
}