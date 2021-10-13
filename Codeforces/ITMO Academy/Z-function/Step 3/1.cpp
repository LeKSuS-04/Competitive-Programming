/* A. Z-функция */
// https://codeforces.com/edu/course/2/lesson/3/3/practice/contest/272263/problem/A
// Date: 20.08.2021 11:05
// Run time: 296 ms
// Memory: 9500 KB
// Verdict: AC

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> z;
string s;

void create_z() {
    z.assign(s.size(), 0);

    int l = 0, r = 0;
    for (int i = 1; i < s.size(); i++) {
        if (i <= r) z[i] = min(z[i - l], r - i + 1);
        while (z[i] + i < s.size() && s[z[i] + i] == s[z[i]]) ++z[i];

        if (z[i] + i - 1 > r) {
            l = i;
            r = z[i] + i - 1;
        }
    }
}

int main() {
    cin >> s;
    create_z();
    for (auto&& i : z) cout << i << " ";
}