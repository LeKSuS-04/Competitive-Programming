/* C. Вхождения префиксов */
// https://codeforces.com/edu/course/2/lesson/3/4/practice/contest/272262/problem/C
// Date: 20.08.2021 12:33
// Run time: 452 ms
// Memory: 13400 KB
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

    string s;
    vector<int> z;
    vector<int> c;
    while (TC--) {
        cin >> s;
        create_z(z, s);

        c.assign(s.size() + 1, 0);
        for (int i = 0; i < z.size(); i++) ++c[z[i]];
        for (int su = 0, i = c.size() - 1; i > 0; i--) su = (c[i] += su);
        for (int i = 1; i < c.size(); i++) cout << c[i] + 1 << " ";
        cout << endl;
    }
}