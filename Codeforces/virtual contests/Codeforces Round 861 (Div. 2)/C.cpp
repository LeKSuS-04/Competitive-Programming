#ifndef LOCALENV
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#include <bits/stdc++.h>
using namespace std;

int luck(const string& s) {
    if (s.size() == 0) return 10;
    return *max_element(s.begin(), s.end()) - *min_element(s.begin(), s.end());
}

string better(const string& a, const string& b) {
    if (luck(a) > luck(b)) return b;
    return a;
}

void change_if_better(string& s, const string& other) {
    if (luck(other) < luck(s)) {
        s = other;
    }
}

string find_best(const string& common_pref, const string& l, const string& r) {
    int i = common_pref.size();
    if (i == l.size()) {
        return l;
    }

    if (r[i] - l[i] > 1) {
        string l_next = common_pref + l[i];







        
        while (l_next.size() != l.size()) {
            l_next += '9';
        }
        string r_prev = common_pref + r[i];
        while (r_prev.size() != r.size()) {
            r_prev += '0';
        }
        string result = better(find_best(common_pref + l[i], l, l_next),
                               find_best(common_pref + r[i], r_prev, r));
        for (char c = l[i] + 1; c < r[i]; c++) {
            string s = common_pref;
            while (s.size() != l.size()) {
                s += c;
            }
            change_if_better(result, s);
        }
        return result;
    }

    string l_next = common_pref + l[i];
    while (l_next.size() != l.size()) {
        l_next += '9';
    }
    string r_prev = common_pref + r[i];
    while (r_prev.size() != r.size()) {
        r_prev += '0';
    }
    return better(find_best(common_pref + l[i], l, l_next),
                  find_best(common_pref + r[i], r_prev, r));
}

signed main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        string l, r;
        cin >> l >> r;
        if (l.size() != r.size()) {
            for (int i = 0; i < l.size(); i++) {
                cout << '9';
            }
            cout << '\n';
            continue;
        }

        string common_pref;
        int i = 0;
        while (i < l.size() && l[i] == r[i]) {
            common_pref += l[i];
            ++i;
        }

        cout << find_best(common_pref, l, r) << '\n';
    }
    cout.flush();
}