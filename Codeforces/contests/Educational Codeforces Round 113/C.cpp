/* C. Jury Meeting */
// https://codeforces.com/problemset/problem/1569/C
// Date: 08.09.2021 19:26
// Runtime: 171ms
// Memory: 144 KB
// Verdict: WA

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

long long fact_mod(int n) {
    long long ans = 1;
    for (int i = 2; i <= n; i++) { ans = (ans * i) % MOD; }
    return ans;
}
long long pow_mod(int a, int k) {
    if (k == 1) return a % MOD;
    else if (k % 2 == 0) {
        long long t = pow_mod(a % MOD, k/2);
        return t * t % MOD;
    } else return (a * pow_mod(a, k - 1)) % MOD;
}
long long c_mod(long long k, long long n) {
	long long a = fact_mod(n);
	long long b = fact_mod(k) * fact_mod(n - k) % MOD;
	long long value = a * pow_mod(b, MOD - 2) % MOD;
	return value;
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;

        int fmx = -1, smx = -1, smxcnt = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (fmx == -1 || a[i] > a[fmx]) smx = fmx, smxcnt = 1,fmx = i;
            else if (smx == -1 || a[i] > a[smx]) smx = i, smxcnt = 1;
            else if (smx != -1 && a[i] == a[smx]) smxcnt++;
        }

        if (a[fmx] > a[smx] + 1) cout << 0 << endl;
        else if (a[fmx] == a[smx]) cout << fact_mod(n) << endl;
        else {
            cout << ((smxcnt * fact_mod(smxcnt)     % MOD) *
                      max(1LL, c_mod(n - smxcnt - 1, n)) % MOD) * 
                      fact_mod(n - smxcnt - 1)          % MOD << endl;
        }
    }
}