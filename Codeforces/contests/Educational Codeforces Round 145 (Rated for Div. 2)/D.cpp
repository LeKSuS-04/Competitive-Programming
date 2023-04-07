/* 1809D. Binary String Sorting */
// https://codeforces.com/contest/1809/problem/D
// Date: Mar/23/2023 19:13
// Run time: 61 ms
// Memory: 2140 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif
    int TC;
    cin >> TC;
    while (TC--) {
        string s;
        cin >> s;
        vector<int> ones(s.size(), 0);
        for (int i = 0; i < s.size(); i++) {
            if (i == 0) {
                ones[i] = s[i] == '1';
            } else {
                ones[i] = (s[i] == '1') + ones[i - 1];
            }
        }
        int total_ones = ones.back();

        pair<int, int> mn = {1e9, 1e9};
        for (int i = 0; i <= s.size(); i++) {
            pair<int, int> cur;
            int ones_before = i == 0 ? 0 : ones[i - 1];
            cur.first =
                ones_before + ((s.size() - i) - (total_ones - ones_before));
            cur.second = cur.first;
            if (i != 0 && i != s.size()) {
                if (s[i - 1] == '1' && s[i] == '0') {
                    cur.first -= 1;
                    cur.second -= 2;
                }
            }

            mn = min(mn, cur);
        }

        if (mn.first == 0) {
            cout << mn.second << '\n';
        } else {
            string a = to_string(mn.first);
            string b = to_string(mn.second);
            cout << a;
            for (int i = 0; i < 12 - b.size(); i++) {
                cout << '0';
            }
            cout << b << '\n';
        }
    }
    cout.flush();
}