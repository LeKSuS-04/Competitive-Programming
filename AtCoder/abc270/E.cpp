/* E - Apple Baskets on Circle */
// https://atcoder.jp/contests/abc270/tasks/abc270_e
// Date: 2022-09-24 16:09:15
// Run time: 82 ms
// Memory: 8780 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto&& ai : a)
        cin >> ai;

    multiset<ll> s;
    for (int i = 0; i < n; i++)
        s.insert(a[i]);

    int i = -1;
    ll ld = 0, d = 0, q = -1;
    for (auto si : s) {
        ll cd = d - ld;
        if (cd != 0) {
            if (cd * (n - i) <= k) {
                k -= cd * (n - i);
            } else {
                q = k / (n - i);
                k -= q * (n - i);
                break;
            }
        }
        ld = d;
        d = si;
        i += 1;
    }

    if (q == -1) {
        q = k / (n - i);
        k -= q * (n - i);
    }

    for (int i = 0; i < n; i++) {
        a[i] = max(a[i] - ld, 0LL);
    }
    for (int i = 0; i < n; i++) {
        a[i] = max(a[i] - q, 0LL);
    }
    for (int i = 0; k > 0; i++) {
        if (a[i] != 0) {
            a[i] -= 1;
            k -= 1;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}