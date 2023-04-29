/* D - AABCC */
// https://atcoder.jp/contests/abc300/tasks/abc300_d
// Date: 2023-04-29 15:54:04
// Run time: 56 ms
// Memory: 12652 KB
// Verdict: AC

#ifndef LOCALENV
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
typedef pair<int, int> ii;
typedef vector<int> vi;

vi primes;
const int MAX = 1e7;
bitset<MAX> is_prime;
void sieve() {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for (int i = 0; i < MAX; i++) {
        if (!is_prime[i]) continue;
        primes.push_back(i);
        for (int j = i * i; j < MAX; j += i) {
            is_prime[j] = false;
        }
    }
}

void solve() {
    int n;
    cin >> n;

    int cnt = 0;
    for (auto a = primes.begin(); (*a) * (*a) * (*a) * (*a) * (*a) < n; a++) {
        for (auto b = a + 1; (*a) * (*a) * (*b) * (*b) * (*b) < n; b++) {
            int t = sqrt(n / ((*a) * (*a) * (*b)));
            auto c = prev(upper_bound(primes.begin(), primes.end(), t));
            cnt += max(ptrdiff_t{0}, distance(b, c));
        }
    }
    cout << cnt << endl;
}

signed main() {
    sieve();
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC = 1;
    // cin >> TC;
    while (TC--) {
        solve();
    }
    cout.flush();
}