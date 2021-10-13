/* E. Странная операция */
// https://codeforces.com/edu/course/2/lesson/3/4/practice/contest/272262/problem/E
// Date: 20.08.2021 13:43
// Run time: 31 ms
// Memory: 5200 KB
// Verdict: AC

#include <algorithm>
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
    vector<int> z1, z2;
    string s, t, t_rev, q1, q2;
    cin >> s >> t;

    if (s.size() != t.size()) {
        cout << "No";
        exit(0);
    }

    t_rev = t, reverse(t_rev.begin(), t_rev.end());
    q1 = s + "$" + t_rev;
    q2 = t + "$" + s;
    create_z(z1, q1);
    create_z(z2, q2);

    for (int i = t.size() + 1; i < q2.size(); i++) {
        if (z2[i] + i == q2.size() && z1[s.size() + 1] >= (i - t.size() - 1)) {
            cout << "Yes" << endl << i - t.size() - 1;
            exit(0);
        }
    }
    cout << "No";
}