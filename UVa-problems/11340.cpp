/* UVa 11340 - Newspaper */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=623&page=show_problem&problem=2315
// Date: 2021-08-19 12:54:25
// Run time: 0.140
// Verdict: AC

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int TC, k, c, m;
    char l;
    long long total;
    unordered_map<char, int> paid;
    string s;
    cin >> TC;

    while (TC--) {
        total = 0;
        paid.clear();

        cin >> k;

        for (int i = 0; i < 256; i++) paid[(char)i] = 0;

        while (k--) {
            cin >> l >> c;
            paid[l] = c;
        }

        cin >> m; getline(cin, s);
        while (m--) {
            getline(cin, s);
            for (int i = 0; i < s.size(); i++) total += paid[s[i]];
        }

        cout << total / 100 << "." << (total % 100 < 10 ? "0" : "") << total % 100 << "$" <<endl;
    }
}