/* A. Suffix Array - 2 */
// https://codeforces.com/edu/course/2/lesson/2/2/practice/contest/269103/problem/A
// Date: 29.09.2021 10:13
// Runtime: 499 ms
// Memory: 26600 KB
// Verdict: AC

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int ASCII_MAX = 256;

vector<int> p, c;

template <class T>
void count_pc(const vector<pair<T, int>>& a) {
    for (int i = 0; i < a.size(); i++)
        p[i] = a[i].second;
    
    c[p[0]] = 0;
    for (int i = 1; i < a.size(); i++)
        c[p[i]] = c[p[i - 1]] + (a[i].first != a[i - 1].first);
}

void radix_sort(vector<pair<pair<int, int>, int>>& viii) {
    vector<int> cntr(viii.size(), 0);
    vector<int> pos(viii.size(), 0);
    for (auto&& iii : viii) ++cntr[iii.first.second];
    for (int i = 1; i < viii.size(); i++) pos[i] = pos[i - 1] + cntr[i - 1];
    vector<pair<pair<int, int>, int>> sorted_viii(viii.size());
    for (auto&& iii : viii) sorted_viii[pos[iii.first.second]++] = iii;
    viii = sorted_viii;

    cntr.assign(viii.size(), 0);
    pos.assign(viii.size(), 0);
    for (auto&& iii : viii) ++cntr[iii.first.first];
    for (int i = 1; i < viii.size(); i++) pos[i] = pos[i - 1] + cntr[i - 1];
    for (auto&& iii : viii) sorted_viii[pos[iii.first.first]++] = iii;
    viii = sorted_viii;
}

int main() {
    string s;
    cin >> s; s += '$';

    p.resize(s.size());
    c.resize(s.size());
    vector<pair<char, int>> a(s.size());
    for (int i = 0; i < s.size(); i++) 
        a[i] = {s[i], i};
    
    vector<int> cntr(ASCII_MAX, 0);
    for (auto&& p : a) ++cntr[p.first];
    vector<int> pos(ASCII_MAX, 0);
    for (int i = 1; i < pos.size(); i++) pos[i] = pos[i - 1] + cntr[i - 1];
    vector<pair<char, int>> a2(s.size());
    for (auto&& p : a) {
        a2[pos[p.first]] = p;
        ++pos[p.first];
    }
    a = a2;

    count_pc(a);
    
    for (int k = 0; (1 << k) < s.size(); k++) {
        vector<pair<pair<int, int>, int>> a(s.size());
        for (int i = 0; i < s.size(); i++)
            a[i] = {{c[i], c[(i + (1 << k)) % s.size()]}, i};
        radix_sort(a);
        count_pc(a);

        if (c[p[s.size() - 1]] == s.size() - 1) break;
    }

    for (int i = 0; i < c.size(); i++)
        cout << p[i] << " ";
    cout << endl;
}