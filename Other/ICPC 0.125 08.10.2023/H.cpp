// Verdict: AC
// #ifndef LOCALENV
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// #define int ll
typedef pair<int, int> ii;
typedef vector<int> vi;

const string MAIN = "main";
const string SIDE = "side";
const string LOW = "low";    // 1
const string HIGH = "high";  // 2

int d = 0;
string last_place, last_section;
void read() { cin >> last_place >> last_section; }
void ask(int i) {
    d += i;
    cout << "? " << i << endl;
    read();
}
void guess(int i) {
    cout << "! " << i - d << endl;
    exit(0);
}

ii reduce(ii lr) {
    auto [l, r] = lr;
    int c = (r - l + 1) / 2;
    if (last_section == MAIN) {
        ask(c);
        if (last_section == MAIN) {
            l += c;
        } else {
            l = 37;
            r += c;
        }
    } else {
        ask(-c);
        if (last_section == SIDE) {
            r -= c;
        } else {
            l -= c;
            r = 36;
        }
    }
    return {l, r};
}

void solve() {
    ask(0);
    ii lr;
    if (last_section == MAIN) {
        lr = {1, 36};
    } else {
        lr = {37, 54};
    }

    for (int i = 0; i < 5; i++) {
        lr = reduce(lr);
    }

    auto [l, r] = lr;
    if (l == r) {
        guess(l);
    }
    if (last_place == HIGH) {
        if (l % 2 == 0) {
            guess(l);
        } else {
            guess(r);
        }
    } else {
        if (l % 2 == 0) {
            guess(r);
        } else {
            guess(l);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC = 1;
    // cin >> TC;
    while (TC--) {
        solve();
    }
    cout.flush();
}