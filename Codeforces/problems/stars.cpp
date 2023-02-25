/* 1A. <name> */
// https://codeforces.com/gym/100246/problem/A
// Date:
// Run time:
// Memory:
// Verdict:

/** THIS TEST CASE MUST YIELD 1 YOU IDIOT
3
1 0 0 0 1
1 0 0 1 1
1 0 0 2 1
1 0 1 0 1
1 0 1 1 1
1 0 1 2 1
1 0 2 0 1
1 0 2 1 1
1 0 2 2 1
1 1 0 0 1
1 1 0 1 1
1 1 0 2 1
1 1 1 0 1
1 1 1 1 1
1 1 1 2 1
1 1 2 0 1
1 1 2 1 1
1 1 2 2 1
1 2 0 0 1
1 2 0 1 1
1 2 0 2 1
1 2 1 0 1
1 2 1 1 1
1 2 1 2 1
1 2 2 0 1
1 2 2 1 1
1 2 2 2 1
2 2 2 2 2 2 2
3
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lsb(ll n) { return n & -n; }

class FenwickTree3D {
   public:
    FenwickTree3D(ll n, ll m, ll k)
        : ft(n + 1, vector<vector<ll>>(m + 1, vector<ll>(k + 1, 0))) {}

    ll sum(ll x, ll y, ll z) {
        ll answ = 0;
        for (ll i = x; i > 0; i -= lsb(i))
        for (ll j = y; j > 0; j -= lsb(j))
        for (ll k = z; k > 0; k -= lsb(k))
            answ += ft[i][j][k];
        return answ;
    }

    ll sum(ll x1, ll y1, ll z1, ll x2, ll y2, ll z2) {
        // TODO: YOU DUMB FUCK
        return sum(x2, y2, z2)
            - sum(x2, y2, z1 - 1)
            - sum(x2, y1 - 1, z2)
            - sum(x1 - 1, y2, z2)
            + 3 * sum(x1 - 1, y1 - 1, z1 - 1);
    }

    void add(ll x, ll y, ll z, ll val) {
        for (ll i = x; i < ft.size(); i += lsb(i))
        for (ll j = y; j < ft[x].size(); j += lsb(j))
        for (ll k = z; k < ft[x][y].size(); k += lsb(k))
            ft[i][j][k] += val;
    }

   private:
    vector<vector<vector<ll>>> ft;
};

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#else
    freopen("stars.in", "r", stdin);
    freopen("stars.out", "w", stdout);
#endif

    ll n, cmd;
    cin >> n;
    FenwickTree3D ftree(n, n, n);

    while (cin >> cmd, cmd != 3) {
        if (cmd == 1) {
            ll x, y, z, k;
            cin >> x >> y >> z >> k;
            ftree.add(++x, ++y, ++z, k);
        } else if (cmd == 2) {
            ll x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            cout << ftree.sum(++x1, ++y1, ++z1, ++x2, ++y2, ++z2) << endl;
        }
    }
}