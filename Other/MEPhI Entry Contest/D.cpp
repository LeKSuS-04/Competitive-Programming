/* D. Отрезки */
// Date: 1 Sep 2022, 11:19:57 (+01:19)
// Run time: 2.672s
// Memory: 11.04Mb
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> as(2*n);
    for (auto&& a : as) cin >> a;

    sort(as.begin(), as.end());

    vector<int> res;
    for (int i = 0; i < as.size() && res.size() < n; i++) {
        if (i == 0) res.push_back(as[i]);
        else {
            if (abs(res[res.size() - 1] - as[i]) > 1) res.push_back(as[i]);
        }
    }

    if (res.size() == n && n > 1) {
        for (auto&& r : res)
            cout << r << endl;
    } else cout << "impossible" << endl;
}