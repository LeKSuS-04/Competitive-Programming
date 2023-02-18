/* A - Non-Adjacent Flip */
// https://atcoder.jp/contests/arc156/tasks/arc156_a
// Date: 2023-02-18 15:25:25
// Run time: 126 ms
// Memory: 3616 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        string s;
        cin >> n >> s;

        int heads = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') ++heads;
        }

        if (heads % 2 == 1) {
            cout << -1 << endl;
            continue;
        }

        if (s == "110" || s == "011" || s == "11") {
            cout << -1 << endl;
            continue;
        }

        if (s == "0110") {
            cout << 3 << endl;
            continue;
        }

        int doubles = 0;
        for (int i = 1; i < s.size(); i++) {
            if ((i < 2 || s[i-2] == '0') && (i > s.size() - 2 || s[i + 1] == '0') && s[i - 1] == '1' && s[i] == '1') {
                doubles += 1;
            }
        }

        if (doubles == 1 && heads == 2) {
            cout << 2 << endl;
        } else {
            cout << heads / 2 << endl;
        }
    }
}