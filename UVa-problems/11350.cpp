/* UVa 11350 - Stern-Brocot Tree */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2325
// Date: 2021-08-18 06:31:54
// Run time: 0.010
// Verdict: AC

#include <iostream>
#include <utility>
#include <stdio.h>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> llp;

llp operator+(llp a, llp b) { return { a.first + b.first, a.second + b.second }; }

int main() {
    int TC;
    llp l, c, r;
    string s;
    cin >> TC;
    while (TC--) {
        cin >> s;
        
        l = { 0, 1 }; r = { 1, 0 };
        for (int i = 0; i < s.size(); i++) {
            if      (s[i] == 'R') l = l + r;
            else if (s[i] == 'L') r = l + r;
        }

        c = l + r;
        cout << c.first << '/' << c.second << '\n';
    }
}