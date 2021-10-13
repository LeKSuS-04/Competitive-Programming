/* A. Минимальный период строки */
// https://codeforces.com/edu/course/2/lesson/3/4/practice/contest/272262/problem/A
// Date: 20.08.2021 12:03
// Run time: 436 ms
// Memory: 10500 KB
// Verdict: AC

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void create_z(vector<int>& z, const string& s) {
    z.assign(s.size(), 0);

    int l = 0, r = 0;
    for (int i = 1; i < s.size(); i++) {
        if (i <= r) z[i] = min(z[i - l], r - i + 1);
        while (z[i] + i < s.size() && s[z[i] + i] == s[z[i]]) ++z[i];
        if (z[i] + i - 1 > r) l = i, r = z[i] + i - 1;
    }
}

int main() {
    int TC;
    cin >> TC;

    vector<int> z;
    string s;
    bool found;
    while (TC--) {
        cin >> s;
        create_z(z, s);

        found = false;
        for (int i = 0; i < z.size() && !found; i++) {
            if (z[i] + i == s.size()) {
                cout << s.substr(0, i) << endl;
                found = true;
            }
        }

        if (!found) cout << s << endl;
    }
}