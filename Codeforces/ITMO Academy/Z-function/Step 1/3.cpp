/* C. Поиск подстроки в строке с джокерами в образце */
// https://codeforces.com/edu/course/2/lesson/3/1/practice/contest/272260/problem/C
// Date: 19.08.2021 17:53
// Run time: 46 ms
// Memory: 4300 KB
// Verdict: AC

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> answ;

void find(const string& t, const string& p) {
    if (t.size() < p.size()) return;

    string sub;
    bool matches;

    for (int i = 0; i < t.size() - p.size() + 1; i++) {
        sub = t.substr(i, p.size());
        matches = true;

        for (int j = 0; j < p.size() && matches; j++) {
            if (!(p[j] == sub[j] || p[j] == '?')) matches = false;
        }

        if (matches) answ.push_back(i);
    }
}

int main() {
    int TC;
    string t, p;
    cin >> TC;

    while (TC--) {
        answ.clear();
        cin >> t >> p;

        find(t, p);
        cout << answ.size() << endl;
        for (int i = 0; i < answ.size(); i++) cout << answ[i] << " ";
        cout << endl;
    }
}