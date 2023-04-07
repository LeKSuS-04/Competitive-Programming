/* 1558B. Up the Strip */
// https://codeforces.com/contest/1558/problem/B
// Date: Aug/25/2021 11:07
// Runtime: 4648 ms
// Memory: 19500 KB
// Verdict: AC

#include <bitset>
#include <iostream>
#include <string.h>
#include <utility>
#include <vector>
using namespace std;

int n, m;
int memo[4000010];
vector<int> primes;

void generate_primes() {
    const int UPPERBOUND = 2010;  // sqrt(4000000);

    bitset<UPPERBOUND> bs;
    bs.set();
    bs[0] = bs[1] = 0;

    for (int i = 2; i < UPPERBOUND; i++)
        if (bs[i]) {
            for (int j = i * i; j < UPPERBOUND; j += i) bs[j] = 0;
            primes.push_back(i);
        }
}

void find_divisors(vector<pair<int, int>>& prime_factors, vector<int>& divisors,
                   int from, int current) {
    if (from >= prime_factors.size()) return;
    find_divisors(prime_factors, divisors, from + 1, current);

    for (int i = 0; i < prime_factors[from].second; i++) {
        current *= prime_factors[from].first;
        divisors.push_back(current);
        find_divisors(prime_factors, divisors, from + 1, current);
    }
}

void find_factors(vector<int>& divisors, int x) {
    vector<pair<int, int>> prime_factors;
    int x_copy = x;
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= x_copy; i++) {
        if (x_copy % primes[i] == 0) prime_factors.push_back({primes[i], 0});

        while (x_copy % primes[i] == 0) {
            x_copy /= primes[i];
            ++prime_factors[prime_factors.size() - 1].second;
        }
    }
    if (x_copy != 1) prime_factors.push_back({x_copy, 1});

    find_divisors(prime_factors, divisors, 0, 1);
    divisors.erase(divisors.end() - 1);
}

int count(int x) {
    if (memo[x] != -1) return memo[x];
    long long ans = (memo[x - 1] + memo[x - 1] + memo[1]) % m;

    vector<int> divisors;
    find_factors(divisors, x);

    for (auto&& d : divisors) {
        ans = (m + ans + memo[d] - memo[d - 1]) % m;
    }
    return memo[x] = ans;
}

void solve() {
    cin >> n >> m;
    memset(memo, -1, sizeof memo);

    memo[1] = 1;
    memo[2] = 2;
    for (int i = 3; i < n; i++) count(i);
    cout << count(n) << endl;
}

int main() {
    generate_primes();
    solve();
}