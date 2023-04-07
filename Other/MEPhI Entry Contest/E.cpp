/* E. Перестановки 3 */
// Date: 1 Sep 2022, 10:55:47 (+00:55)
// Run time: 2.321s
// Memory: 7.81Mb
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXSIZE = 1e6 + 10;
ll fact[10];
ll memo[MAXSIZE];

ll count_perms(int n) {
    if (n == 0) return 1;
    if (n % 3 != 0) return 0;

    int digits[10] = { 0 };
    int total = 0;
    while (n != 0) {
        digits[n % 10] += 1;
        total += 1;
        n /= 10;
    }

    ll s = fact[total];
    if (digits[0] != 0) s = s / total * (total - digits[0]);
    
    for (int i = 0; i < 10; i++)
        if (digits[i] != 0) s /= fact[digits[i]];

    return s;
}

void init() {
    fact[0] = 0;
    fact[1] = 1;
    for (int i = 2; i < 10; i++) fact[i] = fact[i - 1] * i;

    for (int i = 0; i < MAXSIZE; i++) 
        memo[i] = (i == 0 ? 0 : memo[i - 1]) + count_perms(i);
}

int main() {
    init();
    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;
        
        cout << memo[max(b, a)] - memo[min(a, b) - 1] << endl;
    }
}