/* D. LRUD Instructions */
// https://atcoder.jp/contests/abc273/tasks/abc273_d
// Date: 2022-10-15 15:55:14
// Run time: 726 ms	
// Memory: 41452 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

void add(unordered_map<int, vector<int>>& ht, int idx, int val) {
    if (ht.find(idx) == ht.end()) {
        ht[idx] = vector<int>();
    }
    ht[idx].push_back(val);
}

int clamp(int min_, int max_, int val) {
    return min(max_, max(min_, val));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w, rpos, cpos, n, q;
    cin >> h >> w >> rpos >> cpos >> n;

    unordered_map<int, vector<int>> rows;
    unordered_map<int, vector<int>> cols;
    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        
        add(rows, r, c);
        add(cols, c, r);
    }

    for (auto&& row : rows) sort(row.second.begin(), row.second.end());
    for (auto&& col : cols) sort(col.second.begin(), col.second.end());

    cin >> q;
    char d; int l;
    while (q--) {
        cin >> d >> l;

        if (d == 'U') {
            auto it = lower_bound(cols[cpos].begin(), cols[cpos].end(), rpos);
            if (it == cols[cpos].begin()) rpos = clamp(1, h, rpos - l);
            else rpos = clamp(1, h, max(*(it - 1) + 1, rpos - l));
        } else if (d == 'D') {
            auto it = lower_bound(cols[cpos].begin(), cols[cpos].end(), rpos);
            if (it == cols[cpos].end()) rpos = clamp(1, h, rpos + l);
            else rpos = clamp(1, h, min(*it - 1, rpos + l));
        } else if (d == 'L') {
            auto it = lower_bound(rows[rpos].begin(), rows[rpos].end(), cpos);
            if (it == rows[rpos].begin()) cpos = clamp(1, w, cpos - l);
            else cpos = clamp(1, w, max(*(it - 1) + 1, cpos - l));
        } else if (d == 'R') {
            auto it = lower_bound(rows[rpos].begin(), rows[rpos].end(), cpos);
            if (it == rows[rpos].end()) cpos = clamp(1, w, cpos + l);
            else cpos = clamp(1, w, min(*it- 1, cpos + l));
        }

        cout << rpos << ' ' << cpos << endl;
    }
}