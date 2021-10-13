/* UVa 10179 Irreducible Basic Fractions */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1120
// Date: 2021-09-23 15:46:35
// Runtime: 0.010
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

int eul_phi(int n) {
    int ans = n, pf_idx = 0, pf = primes[pf_idx];
    while (pf * pf <= n) {
        if (n % pf == 0) ans -= ans/pf;
        while (n % pf == 0) n /= pf;
        pf = primes[++pf_idx];
    }
    if (n != 1) ans -= ans/n;
    return ans;
}

int main() {
    sieve();
    int n;
    while (cin >> n, n) {
        cout << eul_phi(n) << endl;
    }
}