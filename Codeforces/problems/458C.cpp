/* 458C. Bits */
// https://codeforces.com/problemset/problem/485/C
// Date: 2022-11-25 22:31:38
// Run time: 93 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif

    ll n, l, r;
    cin >> n;
    while (n--) {
        cin >> l >> r;
        ll i = 0;
        while (true) {
            ll p = (1LL << i);
            if ((l & p) == 0) {
                if ((l ^ p) > r) break;
                else l ^= p;
            }
            ++i;
        }
        cout << l << endl;
    }
}