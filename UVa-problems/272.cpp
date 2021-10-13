/* UVa 272 - TEX Quotes */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=208
// Date: 2021-01-15 16:29:58
// Run time: 0.000
// Verdict: AC

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, answer = "";
    int c = 1;
    bool opened = false;

    while (getline(cin, s)) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '"') {
                cout << (opened ? "''" : "``");
                opened = !opened;
            }
            else cout << s[i];
        }

        cout << endl;
    }
}