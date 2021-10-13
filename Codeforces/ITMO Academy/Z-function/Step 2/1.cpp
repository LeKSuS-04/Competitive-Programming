/* A. Z-функция (простая версия) */
// https://codeforces.com/edu/course/2/lesson/3/2/practice/contest/272261/problem/A
// Date: 20.08.2021 07:31
// Run time: 31 ms
// Memory: 3700 KB
// Verdict: AC

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> z;

void get_z(string s) {
    z.assign(s.size(), 0);

    for (int i = 1; i < s.size(); i++) {
        while (z[i] + i < s.size() && s[z[i]] == s[z[i] + i]) ++z[i];
    }
}

int main() {
    string s;
    cin >> s;

    get_z(s);

    for (int i = 0; i < z.size(); i++) cout << z[i] << " ";
}