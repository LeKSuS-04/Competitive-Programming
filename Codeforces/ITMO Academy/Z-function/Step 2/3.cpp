/* C. Строка по z-функции */
// https://codeforces.com/edu/course/2/lesson/3/2/practice/contest/272261/problem/C
// Date: 20.08.2021 09:56
// Run time: 280 ms
// Memory: 3800 KB
// Verdict: AC

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct rule {
    vector<int> must_equal_to;
    vector<int> must_not_equal_to;
};

string find_str(const vector<int>& z) {
    if (z[0] != 0) return "!";

    string alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<rule> rules(z.size());

    for (int i = 1; i < z.size(); i++) {
        int j = 0;
        for (; j < z[i]; j++) {
            if (i + j >= rules.size())
                return "!";
            else
                rules[i + j].must_equal_to.push_back(j);
        }
        if (i + j < rules.size()) rules[i + j].must_not_equal_to.push_back(j);
    }

    string s(z.size(), 0);
    for (int i = 0; i < rules.size(); i++) {
        for (auto&& strict : rules[i].must_equal_to) {
            if (s[i] == 0)
                s[i] = s[strict];
            else if (s[i] != s[strict])
                return "!";
        }

        if (s[i] != 0) {
            for (auto&& not_strict : rules[i].must_not_equal_to) {
                if (s[i] == s[not_strict]) return "!";
            }
        } else {
            bool is_in_list = true;
            for (int j = 0; j <= alpha.size() && is_in_list; j++) {
                is_in_list = false;
                for (auto&& not_strict : rules[i].must_not_equal_to) {
                    if (alpha[j] == s[not_strict]) {
                        is_in_list = true;
                        break;
                    }
                }

                if (!is_in_list) s[i] = alpha[j];
            }
        }
    }

    return s;
}

int main() {
    int TC, n;
    vector<int> z;
    cin >> TC;

    while (TC--) {
        cin >> n;

        z.assign(n, 0);
        for (int i = 0; i < n; i++) cin >> z[i];
        cout << find_str(z) << endl;
    }
}