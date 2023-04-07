/* C. Deep Down Below */
// https://codeforces.com/contest/1561/problem/C
// Date: Aug/24/2021 18:14 (00:39:16)
// Runtime: 561 ms
// Memory: 4428 KB
// Verdict: AC

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, k, m;
        vector<pair<int, int>> a;
        cin >> n;
        a.assign(n, {0, 0});

        for (int i = 0; i < n; i++) {
            cin >> a[i].second;
            for (int j = 0; j < a[i].second; j++) {
                cin >> m;
                a[i].first = max(a[i].first, m - j + 1);
            }
        }

        sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.first != b.first) return a.first < b.first;
            else return a.second > b.second;
        });

        int min_lvl = 0, defeated = 0;
        for (int i = 0; i < n; i++) {
            if (min_lvl + defeated < a[i].first) min_lvl = a[i].first - defeated;
            defeated += a[i].second;
        }
        cout << min_lvl << endl;
    }
}