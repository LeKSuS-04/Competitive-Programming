// Verdict: AC
// #ifndef LOCALENV
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
typedef pair<int, int> ii;
typedef vector<int> vi;

void solve() {
    int n;
    cin >> n;
    string t;
    cin >> t;
    string rev_t = t;
    reverse(rev_t.begin(), rev_t.end());

    vector<string> ss;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ss.push_back(s);
    }

    vector<int> begins(n, 0);
    vector<int> ends(n, 0);

    for (int i = 0; i < n; i++) {
        const string& s = ss[i];
        int k = 0;
        for (int j = 0; j < s.size(); j++) {
            if (k < t.size() && t[k] == s[j]) {
                k++;
            }
        }
        begins[i] = k;
        k = 0;
        for (int j = s.size() - 1; j >= 0; j--) {
            if (k < rev_t.size() && rev_t[k] == s[j]) {
                k++;
            }
        }
        ends[i] = k;
    }

    int max_size = t.size() + 1;
    vector<int> b(max_size, 0);
    vector<int> e(max_size, 0);
    for (const auto& a : begins) {
        ++b[a];
    }
    for (const auto& a : ends) {
        ++e[a];
    }

    for (int i = max_size - 2; i >= 0; i--) {
        b[i] += b[i + 1];
    }

    int answer = 0;
    for (int i = 0; i < max_size; i++) {
        answer += b[i] * e[t.size() - i];
    }

    cout << answer << endl;
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