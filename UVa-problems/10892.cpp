/* UVa 10892 - LCM Cardinality */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1833
// Date: 2021-09-20 17:24:03
// Runtime: 0.040
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
vector<int> find_factors(ll n) {
    vector<int> factors;
    ll a = 1;
    while (a * a <= n) {
        if (n % a == 0) {
            factors.push_back(a);
            if (a * a != n)
                factors.push_back(n / a);
        }
        ++a;
    }
    return factors;
}

int main() {
    int n;
    while (cin >> n, n) {
        auto f = find_factors(n);
        int ans = 0;
        for (int i = 0; i < f.size(); i++)
            for (int j = i; j < f.size(); j++)
                if (lcm(f[i], f[j]) == n) ++ans;
        cout << n << " " << ans << endl;
    }
}