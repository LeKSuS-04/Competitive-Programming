/* B - Mex on Blackboard */
// https://atcoder.jp/contests/arc156/tasks/arc156_b
// Date: 2023-02-18 16:32:06
// Run time: 69 ms
// Memory: 12720 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAX_N = 4e5 + 10;
const ll MOD = 998244353;
ll fact[MAX_N], inv_fact[MAX_N];

ll mod(ll a) { return (a % MOD + MOD) % MOD; }
ll qpow(ll n, ll p) {
    if (p == 0LL) return 1LL;
    if (p % 2 == 0) return qpow(mod(n * n), p / 2);
    return mod(n * qpow(n, p - 1));
}
ll inv(ll a) { return qpow(a, MOD - 2); }

void precompute_fact() {
    fact[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fact[i] = mod(fact[i - 1] * i);
    }

    inv_fact[MAX_N - 1] = inv(fact[MAX_N - 1]);
    for (int i = MAX_N - 2; i >= 0; i--) {
        inv_fact[i] = mod(inv_fact[i + 1] * (i + 1));
    }
}

ll C(ll k, ll n) { return n < k ? 0 : mod(mod(fact[n] * inv_fact[k]) * inv_fact[n - k]); }
ll C2(ll k, ll n) { return C(n - 1, n + k - 1); }

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif
    precompute_fact();

    ll n, k;
    cin >> n >> k;

    vector<ll> a_count(MAX_N, 0);
    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll ai;
        cin >> ai;
        ++a_count[ai];
    }

    ll start_from = 0;
    while (a_count[start_from] != 0) {
        ++start_from;
    }

    ll i = 0, added = 0, last = -1;
    while (added < k) {
        ll mx = start_from + i;
        ++i;
        if (a_count[mx] != 0) {
            continue;
        }

        ll p = k - added;
        res = mod(res + mod(C2(p, mx + 1) - C2(p, last + 1)));
        last = mx;
        added += 1;
    }

    cout << res << endl;
}