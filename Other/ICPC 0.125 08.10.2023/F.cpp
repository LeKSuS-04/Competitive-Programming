// Verdict: AC
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
    ld temp = 0, r1 = 0, r2 = 0, r3 = 0;
    cout << "? 0" << endl;
    cin >> r1;
    cout << "? 90" << endl;
    cin >> r2;
    cout << "? 180" << endl;
    cin >> r3;
    ld c = r1 + r3;
    ld a = sqrt(r1 * r1 + r2 * r2), b = sqrt(r1 * r1 + r3 * r3);

    ld cos1 = (a * a + b * b - c * c) / ((ld)2 * a * b);
    ld sin1 = sqrt((ld)1 - cos1 * cos1);
    ld ans = c / sin1;
    cout << "! " << ((long long)round(ans)) / 2 << endl;
}

int main() {
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}