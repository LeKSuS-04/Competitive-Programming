/* UVa 11955 - Binomial Theorem */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3106
// Date: 2021-09-16 16:50:16
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <string.h>
using namespace std;

const int MAX = 55;
long long C[MAX][MAX];

void precompute() {
    memset(C, 0, sizeof C);
    C[1][1] = 1;
    for (int i = 2; i < MAX; i++)
        for (int j = 1; j <= i; j++)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
}

int main() {
    precompute();

    int TC, case_n = 0;
    cin >> TC;
    while (TC--) {
        string input, a, b;
        int idx = 0, n;

        cin >> input;
        while (input[++idx] != '+') a += input[idx];
        while (input[++idx] != ')') b += input[idx];
        n = stoi(input.substr(idx + 2));

        cout << "Case " << ++case_n << ": ";
        for (int k = 0; k <= n; k++) {
            int ap = n - k, bp = k;

            if (C[n + 1][k + 1] != 1) cout << C[n + 1][k + 1] << "*";
            if (ap != 0) {
                cout << a;
                if (ap != 1) cout << "^" << ap;
            }
            if (bp != 0) {
                if (ap != 0) cout << "*";
                cout << b;
                if (bp != 1) cout << "^" << bp;
            }
            if (k != n) cout << "+";
            else cout << endl;
        }
    }
}