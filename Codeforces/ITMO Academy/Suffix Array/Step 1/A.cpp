/* A. Suffix Array - 1 */
// https://codeforces.com/edu/course/2/lesson/2/1/practice/contest/269100/problem/A
// Date: 28.09.2021 08:50
// Runtime: 264 ms
// Memory: 6700 KB
// Verdict: AC

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<int> p, c;

template <class T>
void count_pc(const vector<pair<T, int>>& a) {
    for (int i = 0; i < a.size(); i++)
        p[i] = a[i].second;
    
    c[p[0]] = 0;
    for (int i = 1; i < a.size(); i++)
        c[p[i]] = c[p[i - 1]] + (a[i].first != a[i - 1].first);
}

int main() {
    string s;
    cin >> s; s += '$';

    p.resize(s.size());
    c.resize(s.size());
    vector<pair<char, int>> a(s.size());
    for (int i = 0; i < s.size(); i++) 
        a[i] = {s[i], i};
    sort(a.begin(), a.end());
    count_pc(a);
    
    for (int k = 0; (1 << k) < s.size(); k++) {
        vector<pair<pair<int, int>, int>> a(s.size());
        for (int i = 0; i < s.size(); i++)
            a[i] = {{c[i], c[(i + (1 << k)) % s.size()]}, i};
        sort(a.begin(), a.end());
        count_pc(a);

        if (c[p[s.size() - 1]] == s.size() - 1) break;
    }

    for (int i = 0; i < c.size(); i++)
        cout << p[i] << " ";
    cout << endl;
}