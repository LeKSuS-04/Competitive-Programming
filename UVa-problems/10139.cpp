/* UVa 10139 - Factovisors */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1080
// Date: 2021-09-22 17:17:14
// Runtime: 0.040
// Verdict: AC

#include <bitset>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 47e3;
bitset<MAX+10> is_prime;
vector<int> primes;
void sieve() {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    primes.clear();
    for (ll i = 2; i < MAX; i++) if (is_prime[i]) {
        for (ll j = i * i; j < MAX; j += i) is_prime[j] = 0;
        primes.push_back(i);
    }
}

vector<ii> factorizate(ll n) {
    vector<ii> ans;
    ll pf_idx = 0, pf = primes[pf_idx], cntr = 0;

    while (pf * pf <= n) {
        cntr = 0;
        while (n % pf == 0) { ++cntr; n /= pf; }
        if (cntr) ans.push_back({pf, cntr});
        pf = primes[++pf_idx];
    }
    if (n != 1) ans.push_back({n, 1});
    return ans;
}

int count_primes(ll fact, ll pf) {
    int ans = 0;
    for (ll i = pf; i <= fact; i *= pf) 
        ans += fact / i;
    return ans;
}

int main() {
    sieve();
    int n, m;
    while (cin >> n >> m) {
        vector<ii> mf = factorizate(m);

        bool divides = true;
        for (auto&& p : mf) {
            if (count_primes(n, p.first) < p.second) {
                divides = false;
                break;
            }
        }

        if (divides)
            cout << m << " divides " << n << "!\n";
        else
            cout << m << " does not divide " << n << "!\n";
    }
}