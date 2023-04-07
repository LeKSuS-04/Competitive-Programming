/* A. Simply Strange Sort */
// https://codeforces.com/contest/1561/problem/A
// Date: Aug/24/2021 17:43 (00:08:44)
// Runtime: 15 ms
// Memory: 3648 KB
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

vector<int> a;

bool sorted() {
    for (int i = 1; i < a.size(); i++)
        if (a[i - 1] > a[i]) return false;
    return true;
}

void f(int i) {
    if (i == a.size() - 1) return;
    if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, c = 0;
        cin >> n;
        a.assign(n, 0);

        for (int i = 0; i < n; i++) cin >> a[i];

        while (!sorted()) {
            for (int i = (c++ % 2 == 0 ? 0 : 1); i < n; i += 2) {
                f(i);
            }
        }
        cout << c << endl;
    }
}