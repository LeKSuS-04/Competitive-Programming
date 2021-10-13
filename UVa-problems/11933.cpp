/* UVa 11933 - Splitting Numbers */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3084
// Date: 2021-07-28 19:04:22
// Run time: 0.000
// Verdict: AC

#include <iostream>
using namespace std;

int main() {
    int n, a, b;
    bool add_to_a;

    while (cin >> n, n) {
        a = b = 0;
        add_to_a = true;

        for (int i = 0; i < 31; i++) {
            if (n & (1 << i)) {
                if (add_to_a) a |= (1 << i);
                else          b |= (1 << i);

                add_to_a = !add_to_a;
            }
        }

        cout << a << " " << b << endl;
    }
}