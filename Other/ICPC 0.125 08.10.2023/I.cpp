// Verdict: AC
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


vector<ll> mas2(100000 + 5);
ll mod = 998244353;
ll mn = 2;

void init() {
    mas2[0] = 1;
    for (int i = 1; i < mas2.size(); i++) {
        mas2[i] = (mas2[i - 1] * mn) % mod;
    }
}

void solve() {
    string s;
    cin >> s;
    vector<int> pr(s.size() + 1);
    int k = 3;
    for (int i = 0; i < s.size(); i++) {
        pr[i + 1] = (pr[i] + s[i] - '0') % k;
    }
    if (pr.back() == 0) {
        ll cnt0 = 0;
        for (int i = 1; i < pr.size(); i++) {
            if (pr[i] == 0) cnt0++;
        }
        ll ans = 1;
        for (int i = 0; i < cnt0 - 1; i++) {
            ans = (ans * mn) % mod;
        }
        cout << ans % mod;
        return;
    }
    
    ll kk = 0;
    ll ans = 0, cnt = 0, ls = pr.back();
    for (int i = 1; i < pr.size(); i++) if (pr[i] == ls) kk++;
    kk--;
    for (int i = 1; i < pr.size(); i++) {
        if (pr[i] == ls) {
            kk--;
            if (kk < 0) kk = 0;
            ll temp1 = mas2[cnt], temp2 = mas2[kk];
            ll tmp = (temp1 * temp2) % mod;
            ans = (ans + tmp) % mod;
        }
        else if (pr[i] == 0) {
            cnt++;
        }
    }
    cout << ans % mod;
    return;
}

int main() {
    init();
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}