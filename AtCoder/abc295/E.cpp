/* E - Kth Number */
// https://atcoder.jp/contests/abc295/tasks/abc295_e
// Verdict: Not Submitted

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 2010;
const int MOD = 998244353;
ll fact[MAX_N], inv_fact[MAX_N];

ll mod(ll a, ll m = MOD) { return (a % m + m) % m; }
ll pow(ll a, ll b, ll m = MOD) {
    if (b == 0)
        return 1;
    else if (b & 1)
        return mod(a * pow(a, b - 1), m);
    else
        return pow(mod(a * a, m), b / 2, m);
}
ll inverse(ll a, ll m = MOD) { return pow(a, m - 2); }
void precompute_fact() {
    fact[0] = 1;
    for (int i = 1; i < MAX_N; i++) fact[i] = mod(fact[i - 1] * i);

    inv_fact[MAX_N - 1] = inverse(fact[MAX_N - 1]);
    for (int i = MAX_N - 2; i >= 0; i--) inv_fact[i] = mod(inv_fact[i + 1] * (i + 1));
}
ll C(ll n, ll k) {
    if (n < k)
        return 0;
    else
        return mod(mod(fact[n] * inv_fact[k]) * inv_fact[n - k]);
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif
    precompute_fact();

    ll n, m, k;
    cin >> n >> m >> k;
    --k;

    vector<ll> a(n);
    for (auto&& ai : a) cin >> ai;

    vector<ll> no_zeros;
    vector<ll> count(m + 1, 0);
    for (auto&& ai : a) {
        if (ai != 0) {
            no_zeros.push_back(ai);
            ++count[ai];
        }
    }
    ll zeros = n - no_zeros.size();
    sort(no_zeros.begin(), no_zeros.end());

    ll num = 0;
    ll den = pow(m, zeros);

    for (ll value = 1; value <= m; value++) {
        for (int pref_size = 0; pref_size < k; value++) {
            ll smaller_amount =
                distance(no_zeros.begin(), lower_bound(no_zeros.begin(), no_zeros.end(), value));
            ll bigger_amount =
                distance(no_zeros.begin(), upper_bound(no_zeros.begin(), no_zeros.end(), value));
            ll equals_amount = bigger_amount - smaller_amount;

            ll l = k - pref_size;
            if (smaller_amount < l) continue;
            ll before_zeros = l - smaller_amount;
            ll equal_zeros = max(0LL, pref_size - equals_amount);
            ll bigger_zeros = zeros - before_zeros - equal_zeros;
            if (bigger_zeros < 0) continue;

            n = mod(n
                + mod(mod(C(zeros, before_zeros) * before_zeros) * (value - 1))
                + mod(mod(C(zeros, equal_zeros) * before_zeros) * (value - 1))
                + mod(mod(C(zeros, before_zeros) * before_zeros) * (value - 1))
            );
        }
    }
    cout << mod(num * inverse(den)) << endl;
}
