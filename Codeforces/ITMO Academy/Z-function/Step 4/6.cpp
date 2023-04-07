/* F. Кратчайшая надстрока */
// https://codeforces.com/edu/course/2/lesson/3/4/practice/contest/272262/problem/F
// Date: 20.08.2021 14:22
// Run time: 576 ms
// Memory: 3200 KB
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

    string s, t, q1, q2;
    vector<int> z1, z2;
    int first, second;
    bool one_contains_another;
    while (TC--) {
        cin >> s >> t;

        q1 = s + "$" + t, create_z(z1, q1);
        q2 = t + "$" + s, create_z(z2, q2);

        first = second = 0;
        one_contains_another = false;
        for (int i = s.size() + 1; i < z1.size() && !one_contains_another; i++) {
            if (z1[i] == s.size()) {
                one_contains_another = true;
                cout << t << endl;
            } else if (i + z1[i] == q1.size()) {
                first = z1[i];
                break;
            }
        }
        for (int i = t.size() + 1; i < z2.size() && !one_contains_another; i++) {
            if (z2[i] == t.size()) {
                one_contains_another = true;
                cout << s << endl;
            } else if (i + z2[i] == q2.size()) {
                second = z2[i];
                break;
            }
        }

        if (!one_contains_another) {
            if (first > second) cout << t << s.substr(first) << endl;
            else                cout << s << t.substr(second) << endl;
        }
    }
}