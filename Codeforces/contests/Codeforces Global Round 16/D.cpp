/* D1/D2. Seating Arrangements */
// https://codeforces.com/contest/1566/problem/D2
// Date: Sep/12/2021 19:23 (01:48:32)
// Runtime: 202 ms
// Memory: 4340 KB
// Verdict: AC

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n >> m;

        vector<ii> a(n*m);
        for (int i = 0; i < n*m; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }

        sort(a.begin(), a.end());

        int discomfort = 0;
        for (int i = 0; i < n; i++) {
            vector<ii> p(m, {-1, -1});
            vector<int> s(m, 0);

            for (int j = 0; j < m; j++) 
                p[j] = {a[i*m + j].second, a[i*m + j].first};

            sort(p.begin(), p.end());
            

            for (int j = 0; j < m; j++) {
                int v = p[j].second, d = 0, idx = 0;

                while (a[i*m + idx].first != v) ++idx;
                while (idx < m - 1 && a[i*m + idx + 1].first == v && s[idx + 1] == 0) ++idx;
                
                s[idx] = 1;
                for (int k = 0; k < idx; k++) 
                    if (s[k]) d += 1;

                discomfort += d;
            }
        }

        cout << discomfort << endl;
    }
}