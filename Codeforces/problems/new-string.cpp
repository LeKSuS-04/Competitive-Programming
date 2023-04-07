/* The 2022 Hangzhou Normal U Summer Trials: B. New String  */
// https://codeforces.com/gym/103736/problem/B
// Date: Aug/02/2022 13:41
// Run time: 93 ms
// Memory: 1000 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

unordered_map<char, char> alphabet;

int cmp(string a, string b) {
    for (int i = 0; i < min(a.size(), b.size()); i++)
        if (a[i] != b[i]) return alphabet[a[i]] - alphabet[b[i]] < 0;
    return a.size() - b.size() < 0;
}

int main() {
    for (int i = 0; i < 26; i++) 
        alphabet[getchar()] = i;

    int n;
    cin >> n;
    vector<string> s(n);
    for (auto&& si : s) cin >> si;

    sort(s.begin(), s.end(), cmp);

    int k;
    cin >> k;
    cout << s[k-1] << '\n';
}