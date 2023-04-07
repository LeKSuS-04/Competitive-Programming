/* B. Префиксный и суффиксные подстроки - 1 */
// https://codeforces.com/edu/course/2/lesson/3/1/practice/contest/272260/problem/B
// Date: 19.08.2021 17:31
// Run time: 46 ms
// Memory: 3800 KB
// Verdict: AC

#include <iostream>
#include <string>
using namespace std;

int exam(const string& s) {
    int c = 0;
    string sub, prefix, suffix;
    for (int len = 0; len < s.size(); len++) {
        prefix = s.substr(0, len);
        suffix = s.substr(s.size() - len);

        for (int i = 0; i < s.size() - len + 1; i++) {
            sub = s.substr(i, len);
            if ((sub == prefix) ^ (sub == suffix)) ++c;
        }
    }
    return c;
}

int main() {
    int TC;
    string s;
    cin >> TC;

    while (TC--) {
        cin >> s;
        cout << exam(s) << endl;
    }
}