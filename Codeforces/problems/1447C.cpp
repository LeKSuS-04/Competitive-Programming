/* 1477C. Knapsack */
// https://codeforces.com/problemset/problem/1447/C
// Date: 2022-11-04 10:02:37
// Run time: 467 ms
// Memory: 3116 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif

    int TC;
    cin >> TC;
    while (TC--) {
        ull n, w;
        cin >> n >> w;

        vector<pair<ull, int>> weights(n);
        for (int i = 0; i < n; i++) {
            cin >> weights[i].first;
            weights[i].second = i + 1;
        }
        for (auto&& [wi, idx] : weights) {
            if ((w + 1) / 2 <= wi && wi <= w) {
                cout << 1 << endl << idx;
                goto END_OF_LOOP;
            }
        }

        {
            sort(weights.begin(), weights.end());
            ull s = 0, amount = 0;
            for (int i = 0; i < n; i++) {
                s += weights[i].first;
                ++amount;
                if (s >= (w + 1) / 2) break;
            }
            if (s > w || s < (w + 1) / 2) {
                cout << -1;
            } else {
                cout << amount << endl;
                for (int i = 0; i < amount; i++) {
                    cout << weights[i].second << ' ';
                }
            }
        }

    END_OF_LOOP:
        cout << endl;
    }
}