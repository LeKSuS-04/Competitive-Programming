/* UVa 10131 - Is Bigger Smarter? */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=651&page=show_problem&problem=1072
// Date: 2021-10-07 05:34:31
// Runtime: 0.000
// Verdict: AC

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
bool cmp(pair<ii, int> a, pair<ii, int> b) {
    if (a.first.first != b.first.first) return a.first.first < b.first.first;
    else if (a.first.second != b.first.second) return a.first.second > b.first.second;
    else return a.second < b.second;
}

vector<pair<ii, int>> e;
vector<ii> lds;

void lds_idx(int idx) {
    for (int i = 0; i < idx; i++) {
        if (e[i].first.second > e[idx].first.second && e[i].first.first != e[idx].first.first && lds[i].first >= lds[idx].first) {
            lds[idx] = {lds[i].first + 1, i};
        }
    }
}

int main() {
    int w, s, i = 1;
    while (cin >> w >> s) {
        e.push_back({{w, s}, i++});
    }

    sort(e.begin(), e.end(), cmp);

    lds.assign(e.size(), {1, -1});
    int idx = 0;
    for (int i = 0; i < e.size(); i++) {
        lds_idx(i);
        if (lds[i] > lds[idx]) idx = i;
    }
    
    vector<int> ans;
    while (idx != -1) {
        ans.push_back(e[idx].second);
        idx = lds[idx].second;
    }

    cout << ans.size() << endl;
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << endl;
}