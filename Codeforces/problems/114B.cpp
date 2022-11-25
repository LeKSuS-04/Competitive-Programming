/* 114B. PFAST Inc. */
// https://codeforces.com/problemset/problem/114/b
// Date: 2022-11-25 21:11:19
// Run time: 186 ms
// Memory: 8 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

template <>
struct std::hash<ii> {
    size_t operator()(const ii& key) const { return (key.first << 10) + key.second; }
};

unordered_map<string, int> mapper_;
unordered_map<int, string> unmapper_;
unordered_map<ii, bool> foes;

int mapper(const string& s) {
    if (mapper_.find(s) == mapper_.end()) {
        mapper_[s] = mapper_.size();
        unmapper_[unmapper_.size()] = s;
    }
    return mapper_[s];
}
string unmapper(int n) { return unmapper_[n]; }
bool are_foes(int a, int b) { return (foes.find({a, b}) == foes.end() ? false : true); }

int main() {
    #ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
    #endif
    
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string k;
        cin >> k;
        mapper(k);
    }

    while (m--) {
        string as, bs;
        cin >> as >> bs;
        int a = mapper(as), b = mapper(bs);
        foes[{a, b}] = foes[{b, a}] = true;
    }

    int max_amount = 0, max_i = 0;
    for (int i = 0; i < (1 << n); i++) {
        bool any_foes = false;
        for (int j = 0; (1 << j) <= i && !any_foes; j++) {
            for (int k = 0; (1 << k) <= i && !any_foes; k++) {
                any_foes |= ((1 << k) & i) && ((1 << j) & i) && are_foes(j, k);
            }
        }

        if (!any_foes) {
            int amount = 0;
            for (int j = 0; (1 << j) <= i; j++) {
                if ((1 << j) & i) ++amount;
            }

            if (amount > max_amount) {
                max_amount = amount;
                max_i = i;
            }
        }
    }

    cout << max_amount << endl;
    vector<string> names;
    for (int i = 0; (1 << i) <= max_i; i++) {
        if ((1 << i) & max_i) {
            names.push_back(unmapper(i));
        }
    }

    sort(names.begin(), names.end());

    for (auto&& s : names) {
        cout << s << endl;
    }
}