/* 356A. Knight Tournament */
// https://codeforces.com/contest/356/problem/A
// Date: Aug/19/2021 15:17
// Run time: 1263 ms
// Memory: 16500 KB
// Verdict: AC

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, m, l, r, x;

    cin >> n >> m;
    vector<int> winners(n + 1);
    set<int> alive; 
    for (int i = 1; i <= n; i++) alive.insert(i), winners[i] = 0;

    vector<set<int>::iterator> to_erase;
    while (m--) {
        to_erase.clear();
        cin >> l >> r >> x;

        for (auto itl = alive.lower_bound(l); itl != alive.upper_bound(r); itl++) {
            if (*itl != x) {
                winners[*itl] = x;
                to_erase.push_back(itl);
            }
        }

        for (auto &&it : to_erase) alive.erase(it);
    }

    for (int i = 1; i <= n; i++) cout << winners[i] << " ";
}

