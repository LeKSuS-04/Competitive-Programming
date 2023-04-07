/* 676C. Vasya and String */
// https://codeforces.com/problemset/problem/676/C
// Date: Sep/11/2022 11:31
// Run time: 31 ms
// Memory: 300 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int try_changing(const string& s, char keep, int n, int k) {
    if (k == 0) {       // I hate this so much >:(
        int c = 1, m = 0;
        for (int i = 1; i < s.size(); i++)
            if (s[i] == s[i - 1]) c += 1;
            else {
                m = max(m, c);
                c = 1;
            }
        return max(m, c);
    }

    int l = 0, r = -1, m = 0;
    vector<char> is_changed(n, 0);

    auto make_move = [&]() {
        ++r;
        m = max(r - l + 1, m);
    };

    while (r < n - 1) {
        if (k == 0) {
            while (r < n - 1 && s[r + 1] == keep) make_move();
            if (is_changed[l]) ++k;
            ++l;
        } else {
            while (r < n - 1 && k != 0) {
                make_move();
                if (s[r] != keep) {
                    is_changed[r] = 1;
                    --k;
                }
            }
        }
    }

    return m;
}

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    cout << max(
        try_changing(s, 'a', n, k),
        try_changing(s, 'b', n, k)
    ) << endl;
}