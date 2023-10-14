// Verdict: Not submitted
#ifndef LOCALENV
#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// #define int ll
typedef pair<int, int> ii;
typedef vector<int> vi;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        uintmax_t hash = std::hash<T1>{}(p.first);
        hash <<= sizeof(uintmax_t) * 4;
        hash ^= std::hash<T2>{}(p.second);
        return std::hash<uintmax_t>{}(hash);
    }
};

const int MAX = 3e6 + 10;
const int MOD = 998'244'353;
unordered_map<string, vector<string>> AL;
unordered_map<pair<string, int>, int> answer;

void precomp() {
    string s =
        "{'IIV': ['IVI'], 'IIX': ['IXI', 'IXV', 'IXX', 'IXC', 'IXL'], 'IVI': ['VIV', 'VIX'], "
        "'IXX': ['XXC', 'XXL'], 'IXC': ['XCX', 'XCC', 'XCL', 'XCD', 'XCM'], 'IXL': ['XLX'], 'VIV': "
        "['IVI'], 'VIX': ['IXI', 'IXV', 'IXX', 'IXC', 'IXL'], 'XXC': ['XCX', 'XCC', 'XCL', 'XCD', "
        "'XCM'], 'XXL': ['XLX'], 'XCC': ['CCD', 'CCM'], 'XCD': ['CDC'], 'XCM': ['CMC', 'CMD', "
        "'CMM'], 'XLX': ['LXC', 'LXL'], 'CCD': ['CDC'], 'CCM': ['CMC', 'CMD', 'CMM'], 'CDC': "
        "['DCD', 'DCM'], 'LXC': ['XCX', 'XCC', 'XCL', 'XCD', 'XCM'], 'LXL': ['XLX'], 'DCD': "
        "['CDC'], 'DCM': ['CMC', 'CMD', 'CMM']}";
    unordered_set<char> alp = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    bool issym = false, isu = false;
    string temp = "", temppar = "";
    for (int i = 2; i < s.size(); i++) {
        if (alp.count(s[i]) && isu == false) {
            temppar += s[i];
        } else if (alp.count(s[i]) && isu == true) {
            temp += s[i];
        } else if (s[i] == '[') {
            isu = true;
        } else if (s[i] == ']') {
            isu = false;
            AL[temppar].push_back(temp);
            temppar = "";
            temp = "";
        } else {
            if (isu == true) {
                AL[temppar].push_back(temp);
                temp = "";
            }
        }
    }
    return;
}

int find_answer(string u, int a) {
    if (answer.find({u, a}) != answer.end()) {
        return answer[{u, a}];
    }

    int s = 0;
    for (const auto& v : AL[u]) {
        s = (s + find_answer(v, a - 1)) % MOD;
    }
    return answer[{u, a}] = s;
}

void solve() {
    int n;
    cin >> n;

    int s = 0;
    for (const auto& [k, _] : AL) {
        s = (s + find_answer(k, n)) % MOD;
    }
    cout << s << endl;
}

signed main() {
    precomp();
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