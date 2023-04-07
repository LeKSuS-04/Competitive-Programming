#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 1e9 + 7;

class Matrix2x2 {
   public:
    Matrix2x2() : a(0), b(0), c(0), d(0) {}
    Matrix2x2(const vector<vector<ll>>& v) : a(v[0][0]), b(v[0][1]), c(v[1][0]), d(v[1][1]) {}

    Matrix2x2 operator*(const Matrix2x2& other) const {
        return Matrix2x2({
            {(a * other.a % MOD + b * other.c % MOD), (a * other.b % MOD + b * other.d % MOD)},
            {(c * other.a % MOD + d * other.c % MOD), (c * other.b % MOD + d * other.d % MOD)},
        });
    }

    Matrix2x2 operator+(const Matrix2x2& other) const {
        return Matrix2x2({{(a + other.a) % MOD, (b + other.b) % MOD},
                          {(c + other.c) % MOD, (d + other.d) % MOD}});
    }

    bool operator==(const Matrix2x2& other) const {
        return a == other.a && b == other.b && c == other.c && d == other.d;
    }
    bool operator!=(const Matrix2x2& other) const { return !(*this == other); }

    ll a, b, c, d;
};

class Vector2D {
   public:
    int x, y;

    Vector2D() : x(0), y(0) {}
    Vector2D(int x, int y) : x(x), y(y) {}

    Vector2D operator*(const Matrix2x2& other) const {
        return Vector2D((other.a * x % MOD + other.b * y % MOD) % MOD,
                        (other.c * x % MOD + other.d * y % MOD) % MOD);
    }
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D((x + other.x) % MOD, (y + other.y) % MOD);
    }

    ll to_fib() { return x; }
};

unordered_map<ll, Matrix2x2> fib_coef_to_power_memo;
const Matrix2x2 fib_coef({{1, 1}, {1, 0}});
const Matrix2x2 identity_matrix({{1, 0}, {0, 1}});
Matrix2x2 fib_coef_to_power(ll p) {
    if (fib_coef_to_power_memo.find(p) != fib_coef_to_power_memo.end()) {
        return fib_coef_to_power_memo[p];
    }

    Matrix2x2 result;
    if (p == 0) {
        result = identity_matrix;
    } else if (p == 1) {
        result = fib_coef;
    } else if (p % 2 == 0) {
        auto tmp = fib_coef_to_power(p / 2);
        result = tmp * tmp;
    } else {
        result = fib_coef * fib_coef_to_power(p - 1);
    }

    if (p < 1e5) {
        fib_coef_to_power_memo[p] = result;
    }
    return result;
}

static Vector2D get_fib_vector(ll n) { return Vector2D(0, 1) * fib_coef_to_power(n); }

class RSQSegmentTree {
   public:
    RSQSegmentTree(ll size) {
        values.resize(size);
        st.resize(4 * size);
        lazy.assign(4 * size, identity_matrix);
        for (auto&& v : values) {
            ll i;
            cin >> i;
            v = get_fib_vector(i);
        }
        build(1, 0, size - 1);
    }

    ll query(ll from, ll to) { return query(1, 0, values.size() - 1, from, to); }
    void add(ll from, ll to, ll value) {
        return add(1, 0, values.size() - 1, from, to, fib_coef_to_power(value));
    }

   private:
    vector<Vector2D> values, st;
    vector<Matrix2x2> lazy;

    ll l(ll p) { return p << 1; }
    ll r(ll p) { return (p << 1) + 1; }

    void propagate(ll p, ll tl, ll tr) {
        st[p] = st[p] * lazy[p];
        if (tl != tr) {
            lazy[l(p)] = lazy[l(p)] * lazy[p];
            lazy[r(p)] = lazy[r(p)] * lazy[p];
        }
        lazy[p] = identity_matrix;
    }

    void build(ll p, ll tl, ll tr) {
        if (tl == tr) {
            st[p] = values[tl];
            return;
        }

        ll m = (tl + tr) / 2;
        build(l(p), tl, m);
        build(r(p), m + 1, tr);
        st[p] = st[l(p)] + st[r(p)];
    }

    ll query(ll p, ll tl, ll tr, ll ql, ll qr) {
        if (lazy[p] != identity_matrix) {
            propagate(p, tl, tr);
        }

        if (ql > tr || qr < tl) return 0;
        if (ql <= tl && tr <= qr) return st[p].to_fib();

        ll m = (tr + tl) / 2;
        ll lsubtree = query(l(p), tl, m, ql, min(qr, m));
        ll rsubtree = query(r(p), m + 1, tr, max(ql, m + 1), qr);
        return (lsubtree + rsubtree) % MOD;
    }

    void add(ll p, ll tl, ll tr, ll ql, ll qr, const Matrix2x2& value) {
        if (lazy[p] != identity_matrix) {
            propagate(p, tl, tr);
        }

        if (ql > tr || qr < tl) return;
        if (ql <= tl && tr <= qr) {
            st[p] = st[p] * value;
            if (tl != tr) {
                lazy[l(p)] = lazy[l(p)] * value;
                lazy[r(p)] = lazy[r(p)] * value;
            }
            return;
        }

        ll m = (tr + tl) / 2;
        add(l(p), tl, m, ql, min(qr, m), value);
        add(r(p), m + 1, tr, max(ql, m + 1), qr, value);
        st[p] = st[l(p)] + st[r(p)];
    }
};

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
    freopen("/home/leksus/Data/Competitive-Programming/IO/output.txt", "w", stdout);
#endif

    for (int i = 1; i < 1e5; i++) {
        fib_coef_to_power(i);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    RSQSegmentTree tree(n);
    while (m--) {
        ll tp, l, r, x;
        cin >> tp >> l >> r;
        --l, --r;
        if (tp == 1) {
            cin >> x;
            tree.add(l, r, x);
        } else {
            cout << tree.query(l, r) << '\n';
        }
    }
}