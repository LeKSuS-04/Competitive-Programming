/* D. Палиндромный префикс */
// https://codeforces.com/edu/course/2/lesson/3/4/practice/contest/272262/problem/D
// Date: 20.08.2021 12:49
// Run time: 77 ms
// Memory: 9700 KB
// Verdict: AC

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s, rev;
vector<int> z;

void create_z() {
    z.assign(rev.size(), 0);

    int l = 0, r = 0;
    for (int i = 1; i < z.size(); i++) {
        if (i <= r) z[i] = min(z[i - l], r - i + 1);
        while (z[i] + i < rev.size() && rev[z[i] + i] == rev[z[i]]) ++z[i];
        if (z[i] + i - 1 > r) l = i, r = z[i] + i - 1; 
    }
}

int main() {
    cin >> s; rev = s;
    reverse(rev.begin(), rev.end());

    rev = s + "$" + rev;
    create_z();

    for (int i = s.size() + 1; i < z.size(); i++) {
        if (z[i] + i == rev.size()) {
            cout << z[i];
            break;
        } 
    }
}