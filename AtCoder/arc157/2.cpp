/* B - XYYYX */
// https://atcoder.jp/contests/arc157/tasks/arc157_b
// Date: 2023-02-25 16:35:19
// Run time: 34 ms
// Memory: 8180 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/Data/Competitive-Programming/IO/input.txt", "r", stdin);
#endif

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int x_count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'X') x_count += 1;
    }

    if (x_count == n) {
        cout << max(k - 1, 0) << endl;
    } else if (x_count == 0) {
        cout << max(n - k - 1, 0) << endl;
    } else if (k <= x_count) {
        int y_segs = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == 'Y' && s[i - 1] == 'Y') {
                y_segs += 1;
            }
        }

        multiset<int> xs;
        int x_seg_count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != 'X' && x_seg_count != 0 && x_seg_count != i) {
                xs.insert(x_seg_count);
            }

            if (s[i] == 'X') {
                x_seg_count += 1;
            } else {
                x_seg_count = 0;
            }
        }

        for (auto&& x_seg : xs) {
            if (k - x_seg >= 0) {
                y_segs += 1 + x_seg;
                k -= x_seg;
            } else {
                break;
            }
        }

        y_segs += k;
        cout << y_segs << endl;
    } else {
        k = k - x_count;

        multiset<int> ys;
        int y_seg_count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != 'Y' && y_seg_count != 0 && y_seg_count != i) {
                ys.insert(y_seg_count);
            }

            if (s[i] == 'Y') {
                y_seg_count += 1;
            } else {
                y_seg_count = 0;
            }
        }

        int y_pairs = n - 1;
        int ys_seg_sum = std::reduce(ys.begin(), ys.end(), 0, [](int a, int b) { return a + b; });
        int ys_side = (n - x_count) - ys_seg_sum;
        int d = min(ys_side, k);
        k -= d;
        y_pairs -= d;

        for (auto it = ys.rbegin(); it != ys.rend(); it++) {
            if (k - *it >= 0) {
                y_pairs -= 1 + *it;
                k -= *it;
            } else {
                break;
            }
        }

        if (k != 0) {
            y_pairs -= k + 1;
        }

        cout << y_pairs << endl;
    }
}