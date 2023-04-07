/* 1806C. Sequence Master */
// https://codeforces.com/contest/1806/problem/C
// Date: 2023-03-18 16:59:16
// Run time: 78 ms
// Memory: 6280 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
vector<ll> p(2 * n);

ll diff(const vector<ll>& a, const vector<ll>& b) {
    ll r = 0;
    for (int i = 0; i < a.size(); i++) {
        r += abs(a[i] - b[i]);
    }
    return r;
}

vector<ll> optimal;
void create_optimal() {
    if (n % 2 == 0) {
        ll max_idx = distance(p.begin(), max_element(p.begin(), p.end()));
        optimal.assign(2 * n, -1);
        optimal[max_idx] = n;
    } else {
        optimal.assign(2 * n, 0);
    }
}

ll solve() {
    if (n == 1) {
        return abs(p[0] - p[1]);
    } else if (n == 2) {
        ll twos = diff(p, vector<ll>(4, 2));
        ll zeros = diff(p, vector<ll>(4, 0));
        create_optimal();
        return min(diff(p, optimal), min(twos, zeros));
    } else {
        ll zeros = diff(p, vector<ll>(2 * n, 0));
        create_optimal();
        return min(diff(p, optimal), zeros);
    }
}

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n;
        p.resize(2 * n);
        for (auto&& pi : p) cin >> pi;

        cout << solve() << '\n';
    }
    cout.flush();
}