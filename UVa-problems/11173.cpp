/* UVa 11173 - Grey Codes */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2114
// Date: 2021-02-18 19:03:42
// Run time: 0.230
// Verdict: AC

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int bits, pos;
        cin >> bits >> pos;
        cout << (pos ^ (pos >> 1)) << "\n";
    }
}