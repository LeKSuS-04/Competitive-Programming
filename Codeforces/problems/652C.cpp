/* 652C. Foe Pairs */
// https://codeforces.com/contest/652/problem/C
// Date: Sep/12/2022 01:56
// Run time: 156 ms
// Memory: 3500 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    vector<int> p(n), unp(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        unp[--p[i]] = i;
    }
 
    vector<int> b_max(n, -1);
    int a, b, x;
    for (int i = 0; i < m; i++) {
        cin >> a >> b; --a, --b;
        x = max(unp[a], unp[b]);
        b_max[x] = max(b_max[x], min(unp[a], unp[b]));
    }
    
    ll s = n, r = 0, l = 0;
    while (l < n) {
        while (r < n && b_max[r] == -1) ++r;
        while (l < n && (r >= n || l <= b_max[r])) {
            s += min(r, n) - l - 1;
            ++l;
        }
        ++r;
    }
    cout << s << endl;
}