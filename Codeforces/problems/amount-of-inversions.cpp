/* C - Количество инверсий */
// https://codeforces.com/gym/100246/problem/C
// Date: 2023-02-27 19:03:38
// Run time: 156 ms
// Memory: 800 KB
// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
   public:
    FenwickTree(int size) : ft(size, 0) {}

    int lsb(int r) { return r & -r; }

    int sum(int r) {
        int res = 0;
        for (; r > 0; r ^= lsb(r)) {
            res += ft[r];
        }
        return res;
    }

    int sum(int l, int r) { return sum(r) - sum(l - 1); }

    void add(int i, int v) {
        for (; i < ft.size(); i += lsb(i)) {
            ft[i] += v;
        }
    }

   private:
    vector<int> ft;
};

int main() {
#ifdef LOCALENV
    freopen("/home/leksus/competitive-programming/IO/input.txt", "r", stdin);
#else
    freopen("inverse.in", "r", stdin);
    freopen("inverse.out", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        a[i] = {ai, i};
    }

    vector<int> mapper(n);
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        mapper[a[i].second] = i + 1;
    }

    int result = 0;
    FenwickTree ftree(a.size() + 1);
    for (auto&& i : mapper) {
        result += ftree.sum(i, n);
        ftree.add(i, 1);
    }
    cout << result << endl;
}