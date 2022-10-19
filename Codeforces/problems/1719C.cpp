/* 1719C. Fighting Tournament */
// https://codeforces.com/problemset/problem/1719/C
// Date: 19.10.2022 18:46
// Run time: 685 ms
// Memory: 4800 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r",
            stdin);
#endif

    int TC;
    cin >> TC;

    while (TC--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (auto&& ai : a) cin >> ai;
        deque<int> da = {a.begin(), a.end()};

        auto maxi = max_element(a.begin(), a.end());
        int max_v = *maxi, max_idx = maxi - a.begin();
        vector<vector<int>> cnt(n + 10, vector<int>());
        for (int i = 0; da.front() != max_v; i++) {
            int x = da.front();
            da.pop_front();
            int y = da.front();
            da.pop_front();
            if (x < y) swap(x, y);
            cnt[x].push_back(i);
            da.push_front(x);
            da.push_back(y);
        }

        int i, k;
        while (q--) {
            cin >> i >> k;
            i = a[i - 1];
            if (i == n) {
                cout << min(k, max(0, k - max_idx + 1)) << endl;
                continue;
            }

            if (cnt[i].size() == 0) {
                cout << 0 << endl;
                continue;
            }

            auto it = lower_bound(cnt[i].begin(), cnt[i].end(), k);
            cout << it - cnt[i].begin() << endl;
        }
    }
}