/* UVa 10680 - LCM */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1621
// Date: 2021-09-22 17:48:30
// Runtime: 0.140
// Verdict: AC

#include <bitset>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int MAX = 1e6+10;
bitset<MAX+10> is_prime;
vector<int> primes;
void sieve() {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    primes.clear();
    for (ll i = 0; i < MAX; i++) if (is_prime[i]) {
        for (ll j = i * i; j < MAX; j += i) is_prime[j] = 0;
        primes.push_back(i);
    }
}

const int MOD = 10;
int pow_mod(int a, int k) {
    if (k == 0) return 1;
    if (k & 1) return (a * pow_mod(a, k - 1)) % MOD;
    return pow_mod(a * a % MOD, k/2);
}
int max_pow_ld(int n, int pf) {
    ll mpow = 0, now = pf;
    while (now <= n) 
        ++mpow, now *= pf;
    return mpow;
}

int find_lcm_ld(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 6;
    if (n == 4) return 12;
    if (n == 5) return 6;

    int pow2 = max_pow_ld(n, 2), 
        pow3 = max_pow_ld(n, 3), 
        pow5 = max_pow_ld(n, 5);

    int lcm = (pow_mod(3, pow3) * pow_mod(2, pow2 - pow5)) % MOD; 
    ll pf_idx = 3, pf = primes[pf_idx];

    while (pf <= n) {
        lcm = (lcm * pow_mod(pf, max_pow_ld(n, pf))) % MOD;
        pf = primes[++pf_idx];
    }
    return lcm;
}

int main() {
    sieve();
    int n;
    while (cin >> n, n) {
        cout << find_lcm_ld(n) << endl;
    }
}