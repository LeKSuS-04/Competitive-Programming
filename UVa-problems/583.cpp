/* UVa 583 - Prime Factors */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=524
// Date: 2021-09-20 16:41:33
// Runtime: 0.220
// Verdict: AC

#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int MAX =  1e7;
bitset<MAX+10> is_prime;
vector<int> primes;
void sieve() {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    primes.clear();
    for (ll i = 2; i < MAX; i++) if (is_prime[i]) {
        for (ll j = i * i; j < MAX; j += i) is_prime[j] = false;
        primes.push_back(i);
    }
}

vector<int> prime_factorization(ll n) {
    vector<int> factors;
    ll pf_idx = 0, pf = primes[pf_idx];
    while (pf * pf <= n) {
        while (n % pf == 0) { n /= pf; factors.push_back(pf); }
        pf = primes[++pf_idx];
    }
    if (n != 1) factors.push_back(n);
    return factors;
}

int main() {
    sieve();
    ll n;
    while (cin >> n, n) {
        cout << n << " = ";
        if (n < 0) { cout << "-1 x "; n *= -1; }
        auto f = prime_factorization(n);
        cout << f[0];
        for (int i = 1; i < f.size(); i++) cout << " x " << f[i];
        cout << endl;
    }
}