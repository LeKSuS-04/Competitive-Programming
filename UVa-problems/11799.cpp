/* UVa 11799 - Horror Dash */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2899
// Date: 2021-02-02 15:49:40
// Run time: 0.040
// Verdict: AC

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;

        int mx = -1;
        int temp;
        while (n--) {
            cin >> temp;
            if (temp > mx) mx = temp;
        }

        cout << "Case " << i << ": " << mx << "\n";
    }
}