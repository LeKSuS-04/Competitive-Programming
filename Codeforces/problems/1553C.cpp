/* 1553C. Penalty */
// https://codeforces.com/problemset/problem/1553/C
// Date: 20.08.2021 19:34
// Run time: 30 ms
// Memory: 3700 KB
// Verdict: AC

#include <iostream>
#include <string>
using namespace std;

string s;

int best(int best_command) {
    int fw = 0, sw = 0, fml = 5, sml = 5;
    for (int i = 0; i < s.size(); i++) {
        if(s[i] == '1') {
            if(i % 2 == 0) ++fw;
            else           ++sw;
        } else if (s[i] == '?') {
            if(i % 2 == 0) fw += !best_command;
            else           sw +=  best_command;
        }
        if(i % 2 == 0) --fml;
        else           --sml;

        if ((!best_command && fw > sw + sml) ||
            ( best_command && sw > fw + fml)) return i;
    }
    return 9;
}

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        cin >> s;
        cout << min(best(0), best(1)) + 1 << endl;
    }
}