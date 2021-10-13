/* UVa 10038 - Jolly Jumpers */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=979
// Date: 2021-07-29 09:39:41
// Run time: 0.000
// Verdict: AC

#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int n, a, b, diff;

    while (cin >> n) {
        bitset<3010> bs;
        cin >> b;

        for (int i = 0; i < n - 1; i++) {
            a = b;
            cin >> b;

            diff = abs(a - b);
            if (diff < 3010) bs[diff] = 1;
        }

        bool isJolly = true;
        for (int i = 1; i <= n - 1 && isJolly; i++) {
            if (!bs[i]) isJolly = false;
        }

        if (isJolly) cout << "Jolly\n";
        else         cout << "Not jolly\n";
    }
}