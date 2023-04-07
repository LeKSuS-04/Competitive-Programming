/* B - Swaps */
// https://codeforces.com/contest/1573/problem/B
// Date: Sep/18/2021 18:48
// Runtime: 171 ms
// Memory: 3800 KB
// Verdict: WA

#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("D:\\Competitive Programming\\Other\\input.txt", "r", stdin);

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int mina = 0, maxb = 0, idx = 0;
        while (a[mina] > b[maxb]) {
            if (a[idx] < a[mina]) mina = idx;
            if (b[idx] > b[maxb]) maxb = idx;
            ++idx;
        }
        cout << mina + maxb << endl;
    }
}