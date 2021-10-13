/* UVa 12405 - Scarecrow */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3836
// Date: 2021-08-08 16:52:57
// Run time: 0.000
// Verdict: AC

#include <iostream>
#include <string>
using namespace std;

int TC, n, c;
string s;

void placeScarecrow(int i) {
    s[i] = '#';
    if (i > 0) s[i - 1] = '#';
    if (i < s.size() - 1) s[i + 1] = '#';
    c++;
}

int main() {
    cin >> TC;

    for (int t = 1; t <= TC; t++) {
        cin >> n >> s;

        for (int i = c = 0; i < s.size(); i++) {
            if (i > 0 && s[i - 1] == '.') placeScarecrow(i);
            else if (i == s.size() - 1 && s[i] == '.') placeScarecrow(i);
        }
        
        cout << "Case " << t << ": " << c << "\n";
    }
}