/* UVa 10684 - The jackpot */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=649&page=show_problem&problem=1625
// Date: 021-07-29 09:53:11
// Run time: 0.080
// Verdict: AC

#include <iostream>
using namespace std;

int main() {
    int n, s, max_s, bet;

    while (cin >> n, n) {
        max_s = s = 0;

        while (n--) {
            cin >> bet;

            s += bet;
            if (max_s < s) max_s = s;
            if (s < 0) s = 0;
        }

        if (max_s > 0) cout << "The maximum winning streak is " << max_s << ".\n";
        else           cout << "Losing streak.\n";
    }
}