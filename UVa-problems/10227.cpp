/* UVa 10227 - Forests */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=636&page=show_problem&problem=1168
// Date: 2021-08-22 17:43:00
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {        
        int p, t, i, j;
        cin >> p >> t;

        vector<vector<bool>> people(p, vector<bool>(100, 0));
        string s;
        istringstream in;
        getline(cin, s);
        while (getline(cin, s), s != "") {
            in = istringstream(s);
            in >> i >> j;
            people[i - 1][j] = 1;
        }

        unordered_map<vector<bool>, int> opinions;
        for (int i = 0; i < people.size(); i++) {
            opinions[people[i]] = 1337;
        }
        cout << opinions.size() << endl;
        if (TC) cout << endl;
    }
}