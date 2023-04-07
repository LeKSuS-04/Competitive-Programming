/* D. Количество хороших подстрок - 1 */
// https://codeforces.com/edu/course/2/lesson/3/1/practice/contest/272260/problem/D
// Date: 19.08.2021 19:31
// Run time: 31 ms
// Memory: 4300 KB
// Verdict: AC

#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long exam(const string& s, const string& t) {
    long long c = 0;

    vector<int> entries = {-1};
    string sub;
    for (int i = 0; i <= int(s.size() - t.size()); i++) {
        sub = s.substr(i, t.size());
        if (sub == t) entries.push_back(i);
    }
    entries.push_back(s.size() - t.size() + 1);

    for (int i = 0; i < entries.size() - 1; i++) {
        c += (entries[i + 1] + t.size() - 2 - entries[i] + 1) *
             (entries[i + 1] + t.size() - 2 - entries[i]) / 2;
    }
    c -= (entries.size() - 2) * (t.size() - 2) * (t.size() - 1) / 2;

    return c;
}

int main() {
    int TC;
    string s, t;
    cin >> TC;

    while (TC--) {
        cin >> s >> t;
        cout << exam(s, t) << endl;
    }
}