// Verdict: AC

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
typedef pair<int, int> ii;
typedef vector<int> vi;

const int MOD = 1e9 + 7;

using Matrix = tuple<int, int, int, int>;

Matrix identityMatrix() {
    return {1, 0, 0, 1};
}

Matrix operator * (const Matrix& a, const Matrix& b) {
    return {
        ((get<0>(a) * get<0>(b) % MOD) + (get<1>(a) * get<2>(b) % MOD)) % MOD,
        ((get<0>(a) * get<1>(b) % MOD) + (get<1>(a) * get<3>(b) % MOD)) % MOD,
        ((get<2>(a) * get<0>(b) % MOD) + (get<3>(a) * get<2>(b) % MOD)) % MOD,
        ((get<2>(a) * get<1>(b) % MOD) + (get<3>(a) * get<3>(b) % MOD)) % MOD,
    };
}

Matrix pow(const Matrix& m, long long p) {
    if (!p)
        return identityMatrix();
    if (p % 2)
        return pow(m, p - 1) * m;
    Matrix r = pow(m, p / 2);
    return r * r;
}

Matrix operator + (const Matrix& a, const Matrix& b) {
    return {
        (get<0>(a) + get<0>(b)) % MOD,
        (get<1>(a) + get<1>(b)) % MOD,
        (get<2>(a) + get<2>(b)) % MOD,
        (get<3>(a) + get<3>(b)) % MOD,
    };
}

Matrix operator - (const Matrix& a, const Matrix& b) {
    return {
        (get<0>(a) - get<0>(b) + MOD) % MOD,
        (get<1>(a) - get<1>(b) + MOD) % MOD,
        (get<2>(a) - get<2>(b) + MOD) % MOD,
        (get<3>(a) - get<3>(b) + MOD) % MOD,
    };
}

ll pow(ll n, ll p) {
    if (p == 0) return 1;
    if (p % 2 == 0) return pow(n * n % MOD, p / 2);
    return (n * pow(n, p - 1)) % MOD;
}

ll inverse(ll n) { return pow(n, MOD - 2); }

Matrix inverse(const Matrix& a) {
    int x, y, z;
    x = get<0>(a);
    y = get<1>(a);
    z = get<3>(a);
    int det = (((x * z) % MOD) - ((y * y) % MOD) + MOD) % MOD;

    int v = inverse(det);
    return {
        get<3>(a) * v % MOD,
        (MOD - get<2>(a)) * v % MOD,
        (MOD - get<1>(a)) * v % MOD,
        get<0>(a) * v % MOD,
    };
}

void solve() {
    int l, r, m;
    cin >> l >> r >> m;
    int k = r / m;

    const Matrix F = {1, 1, 1, 0};
    const Matrix E = identityMatrix();

    Matrix M = pow(F, m);
    Matrix K = pow(M, r/m - l/m);

    Matrix Q = (pow(M, k - l/m + 1) - E) * inverse(M - E);
    Matrix X_a = pow(F, l - l % m);
    Matrix X_b = pow(F, l - l % m + 1);
    for (int i = 0; i < m; i++) {
        Matrix X;
        if (i == 0) {
            X = X_a;
        } else if (i == 1) {
            X = X_b;
        } else {
            X = X_a + X_b;
        }

        Matrix S = X * Q;
        if (i < l % m) {
            S = S - X;
        }
        if (i > r % m) {
            S = S - X * K;
        }
        cout << get<1>(S) << ' ';

        if (i > 1) {
            X_a = X_b;
            X_b = X;
        }
    }
    cout << endl;
}

signed main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC = 1;
    // cin >> TC;
    while (TC--) {
        solve();
    }
    cout.flush();
}