/* 1705C. Mark and His Unfinished Essay  */
// https://codeforces.com/contest/1705/problem/C
// Date: Jul/27/2022 11:25
// Run time: 155 ms 	 
// Memory: 500 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct cp {
    ll start, length, ref;
};

string s;
vector<cp> copypasta;

char query(ll q) {
    if (q < s.size()) return s[q];
    else for (auto c : copypasta) {
        if (q < c.start + c.length)
            return query(c.ref + (q - c.start));
    }
}

int main() {
    int TC; cin >> TC;
    while (TC--) {
        int n, c, q;
        cin >> n >> c >> q >> s;

        copypasta.resize(c);
        ll l, r, length = s.size();
        for (auto&& cpi : copypasta) {
            cin >> l >> r;
            cpi.ref = l - 1;
            cpi.start = length;
            length += (cpi.length = r - l + 1);
        }
        
        ll k;
        while (q--) {
            cin >> k;
            cout << query(k - 1) << '\n';
        }
    }
}