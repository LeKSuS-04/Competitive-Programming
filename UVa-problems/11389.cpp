/* 11389 - The Bus Driver Problem */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2384
// Date: 2021-08-08 17:14:11
// Run time: 0.000
// Verdict: AC

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
    ll n, d, r, c;
    vi m, e; 

    while (cin >> n >> d >> r, n | d | r) {
        m.assign(n, 0);
        e.assign(n, 0);

        for (int i = 0; i < n; i++) cin >> m[i];
        for (int i = 0; i < n; i++) cin >> e[i];

        sort(m.begin(), m.end());
        sort(e.begin(), e.end());

        for(int i = c = 0; i < n; i++) {
            c += max(1LL * 0, m[i] + e[n - 1 - i] - d);
        }

        cout << c * r << endl;
    }
}