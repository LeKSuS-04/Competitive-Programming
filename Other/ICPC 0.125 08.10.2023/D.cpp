// Verdict: AC
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll anss(ll a) {
    ll ans = 0;
    for (ll i = 1; i <= sqrtl(a); i++) {
        if (a % i == 0) {
            if (i == sqrtl(a)) ans++;
            else ans+=2;
        }
    }
    return ans;
}

void solve() {
    ll q, r;
    cin >> q >> r;
    ll temp = q * r - q; // найти все делители этого числа
    ll t = anss(temp);
    cout << t;
}

int main() {
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}