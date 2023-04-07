/* 1512C. A-B Palindrome */
// https://codeforces.com/contest/1512/problem/C
// Date: Sep/17/2022 15:20
// Run time: 46 ms
// Memory: 500 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int a, b;
        string s;
        cin >> a >> b >> s;

        int n = a + b;
        int a_cnt = 0, b_cnt = 0;
        for (int i = 0; i < (n+1)/2; i++) {
            int j = n - i - 1;
            if (s[i] == '?' && s[j] != '?') {
                if (s[j] == '0') s[i] = '0';
                else s[i] = '1';
            }
            if (s[i] != '?' && s[j] == '?') {
                if (s[i] == '0') s[j] = '0';
                else s[j] = '1';
            }

            a_cnt += ((int) (s[i] == '0')) + ((int) (s[j] == '0') - (int) (i == j && s[i] == '0'));
            b_cnt += ((int) (s[i] == '1')) + ((int) (s[j] == '1') - (int) (i == j && s[i] == '1'));
        }

        if (a_cnt > a || b_cnt > b) cout << -1 << endl;
        else {
            int a_left = a - a_cnt, b_left = b - b_cnt;
            bool aborted = false;
            for (int i = 0; i < (n+1)/2; i++) {
                int j = n - i - 1;
                if (s[i] != s[j]) {
                    aborted = true;
                    break;
                }

                if (s[i] == '?') {
                    char the_chosen_one;

                    if (a_left > b_left) {
                        the_chosen_one = '0';
                        a_left -= 1 + (i != j);
                    } else {
                        the_chosen_one = '1';
                        b_left -= 1 + (i != j);
                    }

                    s[i] = s[j] = the_chosen_one;
                }
            }

            if (aborted || b_left != 0 || a_left != 0) {
                cout << -1 << endl;
            } else {
                cout << s << endl;
            }
        }
    }
}