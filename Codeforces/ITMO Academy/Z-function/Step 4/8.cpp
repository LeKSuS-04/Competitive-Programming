/* H. Сумма длин различных подстрок */
// https://codeforces.com/edu/course/2/lesson/3/4/practice/contest/272262/problem/H
// Date: 20.08.2021 16:56
// Run time: 217 ms
// Memory: 4100 KB
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
    string s, post;
    cin >> s;

    long long sum = 0, mxi, a;
    vector<int> z;
    for (int i = 1; i <= s.size(); i++) {
        post = s.substr(s.size() - i);
        create_z(z, post);
        
        mxi = 0;
        for (int i = 0; i < z.size(); i++) 
            if (z[i] > z[mxi]) mxi = i;

        sum += (i + z[mxi] + 1) * (i - z[mxi]) / 2;
    }
    cout << sum << endl;
}