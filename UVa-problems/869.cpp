/* UVa 869 - Airline Comparison */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=683&page=show_problem&problem=810
// Date: 2021-09-02 15:52:43
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        char u, v;

        vector<vector<int>> AM1, AM2;
        AM1.assign(26, vector<int>(26, 0));
        AM2.assign(26, vector<int>(26, 0));

        cin >> n;
        while (n--) {
            cin >> u >> v;
            AM1[u - 'A'][v - 'A'] = AM1[v - 'A'][u - 'A'] = 1;
        }
        cin >> m;
        while (m--) {
            cin >> u >> v;
            AM2[u - 'A'][v - 'A'] = AM2[v - 'A'][u - 'A'] = 1;
        }

        for (int k = 0; k < 26; k++) 
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++) {
                    AM1[i][j] |= (AM1[i][k] & AM1[k][j]);
                    AM2[i][j] |= (AM2[i][k] & AM2[k][j]);
                }

        bool similar = true;
        for (int i = 0; i < 26; i++) 
            for (int j = 0; j < 26; j++)
                similar &= (AM1[i][j] == AM2[i][j]);

        cout << (similar ? "YES" : "NO") << endl;
        if (TC) cout << endl;
    }
}