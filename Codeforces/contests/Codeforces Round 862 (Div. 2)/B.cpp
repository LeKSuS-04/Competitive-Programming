/* 1805B. The String Has a Target */
// https://codeforces.com/contest/1805/problem/B
// Date: 2023-04-02 17:47:28
// Run time: 46 ms
// Memory: 5064 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        string s;
        cin >> n >> s;
        multiset<char> symbols;
        for (int i = 0; i < s.size(); i++) {
            symbols.insert(s[i]);
        }

        if (s[0] != *symbols.begin()) {
            cout << *symbols.begin();
            string res;
            bool met = false;
            for (int i = n - 1; i >= 0; i--) {
                if (!met && s[i] == *symbols.begin()) {
                    met = true;
                } else {
                    res += s[i];
                }
            }
            reverse(res.begin(), res.end());
            cout << res << endl;
        } else {
            int c = 0;
            while (c < s.size() && s[c] == *symbols.begin()) ++c;
            if (c == symbols.count(*symbols.begin())) {
                cout << s << endl;
            } else {
                cout << *symbols.begin();
                string res;
                bool met = false;
                for (int i = n - 1; i >= 0; i--) {
                    if (!met && s[i] == *symbols.begin()) {
                        met = true;
                    } else {
                        res += s[i];
                    }
                }
                reverse(res.begin(), res.end());
                cout << res << endl;
            }
        }
    }
}