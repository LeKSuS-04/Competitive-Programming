/* UVa 294 - Divisors */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=230
// Date: 2021-09-23 04:37:16
// Runtime: 0.000
// Verdict: AC

#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 32e3;
bitset<MAX+10> is_prime;
vector<int> primes;
void sieve() {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    primes.clear();

    for (int i = 2; i < MAX; i++) if (is_prime[i]) {
        for (int j = i * i; j < MAX; j += i) is_prime[j] = 0;
        primes.push_back(i);
    }
}

int num_of_divs(int n) {
    int ans = 1;
    int pf_idx = 0, pf = primes[pf_idx];

    while (pf * pf <= n) {
        int pwr = 0;
        while (n % pf == 0) { ++pwr; n /= pf; }
        ans *= (pwr + 1);

        pf = primes[++pf_idx];
    }
    if (n != 1) ans *= 2;
    return ans;
}

int main() {
    sieve();

    int TC;
    cin >> TC;
    while (TC--) {
        int l, u;
        cin >> l >> u;

        int mx_n, n_divs = 0;
        for (int i = l; i <= u; i++) {
            int divs = num_of_divs(i);
            if (divs > n_divs) {
                mx_n = i;
                n_divs = divs;
            }
        }

        cout << "Between " << l << " and " << u << ", " << mx_n << " has a maximum of " << n_divs << " divisors.\n";
    }
}