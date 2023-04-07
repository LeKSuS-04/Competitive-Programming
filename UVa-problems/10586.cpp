/* UVa 10586 - Polynomial Remains */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1527
// Date: 2021-09-11 16:52:14
// Runtime: 0.010
// Verdict: AC

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    while (cin >> n >> k, !(k == -1 && n == -1)) {
        int pwr = n - k, coef;
        vector<int> poly(n + 1);
        for (int i = 0; i <= n; i++) 
            cin >> poly[i];

        if (k == 0) {
            cout << "0\n";
        } else {
            while (pwr > -1) {
                coef = poly[k + pwr];
                if(coef != 0) {
                    poly[k + pwr] -= coef;
                    poly[pwr]     -= coef;
                }
                --pwr;
            }

            while (poly.size() > 0 && poly.back() == 0)
                poly.pop_back();

            if (poly.size() > 0) {
                cout << poly[0];
                for (int i = 1; i < poly.size(); i++)
                    cout << " " << poly[i];
                cout << endl;
            } else {
                cout << "0\n";
            }
        }
    }
}