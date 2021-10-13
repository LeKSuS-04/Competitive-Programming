/* A. Наидлиннейший палиндромный префикс - 1 */
// https://codeforces.com/edu/course/2/lesson/3/1/practice/contest/272260/problem/A
// Date: 19.08.2021 17:17
// Run time: 15 ms
// Memory: 3700 KB
// Verdict: AC

#include <iostream>
#include <string>
using namespace std;

bool is_palindrom(const string& s) {
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) return false;
    }
    return true;
}

int longest_palindrom(const string& s) {
    for (int i = s.size(); i > -1; i--) {
        if (is_palindrom(s.substr(0, i))) return i;
    }
    return -1;
}

int main() {
    int t;
    cin >> t;

    string s;
    while (t--) {
        cin >> s;
        cout << longest_palindrom(s) << endl;
    }
}