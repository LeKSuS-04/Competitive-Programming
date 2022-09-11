/* 701C. They Are Everywhere */
// https://codeforces.com/problemset/problem/701/C
// Date: Sep/11/2022 13:32
// Run time: 31 ms
// Memory: 300 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int unique = 0;
    vector<char> unique_count(256, 0);
    for (int i = 0; i < s.size(); i++) 
        unique_count[s[i]] = 1;
    for (int i = 0; i < unique_count.size(); i++) 
        unique += unique_count[i];

    int l = 0, r = 0, c = 0, m = n;
    vector<int> amount(256, 0);
    ++amount[s[0]];
    ++c;
    
    // :scream:
    while (r < n - 1 && c != unique) {
        ++r;
        if (amount[s[r]] == 0) ++c;
        ++amount[s[r]];
    }
    do {
        while (amount[s[l]] > 1) {
            --amount[s[l]];
            ++l;
        }

        m = min(m, r - l + 1);
        ++r;
        if (amount[s[r]] == 0) ++c;
        ++amount[s[r]];
    } while (r < n - 1);
    while (amount[s[l]] > 1) {
        --amount[s[l]];
        ++l;
    }

    m = min(m, r - l + 1);

    cout << m << endl;
}