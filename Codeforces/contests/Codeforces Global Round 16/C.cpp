/* C. MAX-MEX Cut */
// https://codeforces.com/contest/1566/problem/C
// Date: Sep/12/2021 18:13 (00:38:39)
// Runtime: 77 ms
// Memory: 4000 KB
// Verdict: AC

#include <iostream>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        string a, b;
        cin >> n >> a >> b;

        int s = 0;
        bool has_one = false, has_zero = false, skip = false;
        for (int i = 0; i < n; i++) {     
            if (skip) {
                skip = false;
                continue;
            }

            has_one |= (a[i] == '1' || b[i] == '1');
            has_zero |= (a[i] == '0' || b[i] == '0');

            if (has_one && has_zero) {
                s += 2;
                has_one = has_zero = 0;
            } else if (has_zero) {
                if (i != n - 1) {
                    if (a[i + 1] == '1' && b[i + 1] == '1') {
                        s += 2;
                        has_one = has_zero = 0;
                        skip = true;
                    } else {
                        s += 1;
                        has_one = has_zero = 0;
                    }
                } else s += 1;
            }
        }

        cout << s << endl;
    }
}