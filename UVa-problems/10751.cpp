/* UVa 10751 - Chessboard */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1692
// Date: 2021-09-11 12:35:58
// Runtime: 0.000
// Verdict: AC

#include <iomanip>
#include <iostream>
using namespace std;

const double STRAIGHT = 1.0;
const double DIAGONAL = 1.41421356237;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;


        double dist = ((n - 2) * (n - 3) + n - 2) * DIAGONAL +
                      4 * (n - 1) * STRAIGHT;

        if (n == 1) 
            cout << "0.000\n";
        else 
            cout << fixed << setprecision(3) << dist << endl;
        if (TC) cout << endl;
    }
}