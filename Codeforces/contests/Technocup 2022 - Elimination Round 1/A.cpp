/* A - Windblume Ode */
// https://codeforces.com/contest/1583/problem/A
// Date: Oct/17/2021 14:25 (00:20:24)
// Runtime: 15 ms
// Memory: 0 KB
// Verdict: AC

#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 20100;
bitset<MAX> is_prime;
void sieve() {
    is_prime.set();
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i < MAX; i++) if (is_prime[i]) 
        for (int j = i * i; j < MAX; j += i) is_prime[j] = false;
}

int main() {
    sieve();

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto&& ai : a) cin >> ai;

        int sum = 0;
        for (auto&& ai : a) sum += ai;

        if (!is_prime[sum]) {
            cout << n << endl;
            for (int i = 1; i <= n; i++) cout << i << " ";
        } else {
            int idx_exc = -1;
            for (int i = 0; i < n; i++) 
                if (!is_prime[sum - a[i]]) {
                    idx_exc = i;
                    break;
                }
            
            cout << n - 1 << endl;
            for (int i = 1; i <= n; i++) if (i != idx_exc + 1) cout << i << " ";
        }
        cout << endl;
    }
}