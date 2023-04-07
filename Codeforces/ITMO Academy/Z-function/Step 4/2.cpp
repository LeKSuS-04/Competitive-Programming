/* B - Циклические сдвиги */
// https://codeforces.com/edu/course/2/lesson/3/4/practice/contest/272262/problem/B
// Date: 20.08.2021 12:16
// Run time: 577 ms
// Memory: 23200 KB
// Verdict: AC

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void create_z(vector<int>& z, const string& s) {
    z.assign(s.size(), 0);

    int l = 0, r = 0;
    for (int i = 1; i < z.size(); i++) {
        if (i <= r) z[i] = min(z[i - l], r - i + 1);
        while (z[i] + i < s.size() && s[z[i] + i] == s[z[i]]) ++z[i];
        if (z[i] + i - 1 > r) l = i, r = z[i] + i - 1;
    }
}

int main() {
    int TC;
    cin >> TC;

    string s, t, m;
    vector<int> z;
    bool found;
    while (TC--) {
        cin >> s >> t;
        m = t + "$" + s + s;
        create_z(z, m);

        found = false;
        for (int i = t.size() + 1; i < t.size() + 1 + s.size() && !found; i++) {
            if (z[i] == t.size()) {
                found = true;
                cout << i - t.size() - 1 << endl;
            }
        }
        if (!found) cout <<  -1 << endl;
    }
}