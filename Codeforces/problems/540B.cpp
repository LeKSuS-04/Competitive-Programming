/* 540B. School Marks */
// https://codeforces.com/problemset/problem/540/B
// Date: Sep/11/2022 19:39
// Run time: 15 ms
// Memory: 0 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;
    deque<int> a(k);
    int s = 0;
    for (auto&& ai : a) {
        cin >> ai;
        s += ai;
    }
    
    sort(a.begin(), a.end());
    int med_pos = (k)/2;

    vector<int> answ;
    int added_to_a = 0;
    if (a[med_pos] < y) {
        int l = 0;
        bool breaked = false;
        for (int i = med_pos; i < k && !breaked; i++) {
            if (a[i] >= y) {
                l = 2*i - k + 1;
                breaked = true;
            }
        }
        if (!breaked) {
            l = k + 1;
        }
        
        answ.assign(l, y);
        s += l * y;
    } else {
        if (k % 2 == 0) {
            if (k != 0 && a[med_pos - 1] >= y) {
                a.push_front(1);
                answ.push_back(1);
                s += 1;
            } else {
                a.push_back(y);
                answ.push_back(y);
                s += y;
            }
            added_to_a = 1;
            ++k;
        }

        int l;
        for (l = 0; a[l] < y; l++);
        for (int i = 0; i < min(n - k, k - 2*l - 1); i++)
            answ.push_back(1);
        s += min(n - k, k - 2*l - 1);
    }

    if (k + answ.size() - added_to_a > n) {
        cout << -1 << endl;
        return 0;
    }

    while (k + answ.size() - added_to_a < n) {
        answ.push_back(1);
        answ.push_back(y);
        s += 1 + y;
    }
    
    if (s > x) cout << -1;
    else for (auto&& ai : answ) cout << ai << ' ';
    cout << endl;
}
