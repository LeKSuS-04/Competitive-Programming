/* C -  Manga */
// https://atcoder.jp/contests/abc271/tasks/abc271_c
// Date: 2022-10-01 16:27:51	
// Run time: 252 ms	
// Memory: 18784 KB	
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    deque<int> a(n);
    for (auto&& ai : a) cin >> ai;

    set<int> unique;
    for (int i = 0; i < a.size(); i++)
        unique.insert(a[i]);

    int v = a.size() - unique.size();

    a.resize(0);
    for (auto it = unique.begin(); it != unique.end(); it++) {
        a.push_back(*it);
    }

    int c = 1;
    while (a.size() != 0) {
        if (a[0] == c) {
            c++;
            a.pop_front();
        } else {
            if (v >= 2) {
                v -= 2;
                c++;
            } else {
                a.pop_back();
                v++;
            }
        }
    }

    while (v >= 2) {
        v -= 2;
        c++;
    }

    cout << c - 1 << endl;
}