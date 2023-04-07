/* UVa 10226 - Hardwood Species */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1167
// Date: 2021-09-06 16:04:00
// Runtime: 0.440
// Verdict: AC

#include <iomanip>
#include <iostream>
#include <map>
using namespace std;

struct zero_int { int value = 0; };

int main() {
    int TC;
    cin >> TC;
    
    string line;
    getline(cin, line);
    getline(cin, line);
    while (TC--) {
        double s = 0;
        map<string, zero_int> trees;

        while (getline(cin, line), line != "") {
            trees[line].value += 1;
            s += 1;
        }

        for (auto&& t : trees) 
            cout << t.first << " " << fixed << setprecision(4) << t.second.value*100/s << endl;
        if (TC) cout << endl;
    }
}