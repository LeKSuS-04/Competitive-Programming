/* 1244E. Minimizing Difference */
// https://codeforces.com/problemset/problem/1244/E
// Date: 2022-10-19 20:23:46
// Run time: 296 ms
// Memory: 14244 KB
// Verdict: ACs

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

set<ll> a;
multiset<ll> cnt_a;
unordered_map<ll, ll> counter;

ll count(ll val) {
    if (counter.find(val) != counter.end()) {
        return (*counter.find(val)).second;
    }
    return counter[val] = cnt_a.count(val);
}

int main() {
    #ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
    #endif
    
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        ll ai;
        cin >> ai;
        a.insert(ai);
        cnt_a.insert(ai);
    }

    auto l = a.begin();
    auto r = prev(a.end());
    ll lcnt = 0, rcnt = 0;
    ll mn = *l, mx = *r;
    while (l != r) {
        if (lcnt + count(*l) < rcnt + count(*r)) {
            lcnt += count(*l);
            ll d = *next(l) - *l;
            if (lcnt * d <= k) {
                k -= lcnt * d;
                mn = *next(l);
            } else {
                mn += k / lcnt;
                break;
            }
            ++l;
        } else {
            rcnt += count(*r);
            ll d = (*r - *prev(r));
            if (rcnt * d <= k) {
                k -= rcnt * d;
                mx = *prev(r);
            } else {
                mx -= k / rcnt;
                break;
            }
            --r;
        }
    }

    cout << mx - mn << endl;
}