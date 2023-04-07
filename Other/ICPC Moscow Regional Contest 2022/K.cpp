// K. Две цифры факториала
// Not submitted

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const ull MOD = 100ULL;

ull qpow(ull x, ull p) {
    if (p == 0) return 1;
    if (p % 2 == 1) return x * qpow(x, p - 1) % MOD;
    return qpow(x * x % MOD, p / 2);
}

ull endswith_before(int endswith, int before) {
    return before / 100 + (endswith <= before % 100 ? 1 : 0);
}

ull solve_no_2(ull n) {
    if (n == 0) return 1;
    vector<ull> cnt(100, 0);

    ull res = 1, carma = 0, p = n;
    while (p != 0) {
        ull prod = solve_no_2(p / 5);
        res = (res * prod * prod) % MOD;

        for (int i = 1; i < min(100ULL, p + 1); i++) {
            if (i % 5 == 0) continue;
            cnt[i] += endswith_before(i, p);
            if (i % 2 == 0) cnt[i] -= endswith_before(i, 2 * p / 5);
        }

        p /= 10;
    }

    for (int i = 1; i < 100; i++) {
        if (cnt[i] == 0 && i % 2 == 0) continue;
        res = (res * qpow(i, cnt[i])) % MOD;
    }

    return res;
}

ull solve(ull n) {
    if (n == 0) return 1;
    vector<ull> cnt(100, 0);

    ull res = 1, carma = 0, p = n;
    while (p != 0) {
        ull prod = solve_no_2(p / 5);
        res = (res * prod * prod) % MOD;

        for (int i = 1; i < min(100ULL, p + 1); i++) {
            if (i % 5 == 0) continue;
            cnt[i] += endswith_before(i, p);
            if (i % 2 == 0) cnt[i] -= endswith_before(i, 2 * p / 5);
        }

        p /= 10;
    }

    for (int i = 1; i < 100; i++) {
        if (cnt[i] == 0) continue;
        res = (res * qpow(i, cnt[i])) % MOD;
    }

    return res;
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r",
            stdin);
#endif

    ull n;
    cin >> n;

    ull res = solve(n);
    if (res < 10 && n > 2) cout << '0';
    cout << res << endl;
}