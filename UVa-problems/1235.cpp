/* UVa 1235 - Anti Brute Force Lock */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=673&page=show_problem&problem=3676
// Date: 2021-08-27 06:26:46
// Runtime: 0.160
// Verdict: AC

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int rolls(int a, int b) {
    return min(abs((10 + b % 10 - a % 10) % 10),
               abs((10 + a % 10 - b % 10) % 10));
}

int num_of_rolls(int a, int b) {
    int ans = 0;
    while (!(a == 0 && b == 0)) {
        ans += rolls(a, b);
        a /= 10;
        b /= 10;
    }
    return ans;
}

class UFDS {
   private:
    int sets;
    vector<int> p, rank;

   public:
    UFDS(int n) {
        p.assign(n, 0);
        for (int i = 0; i < n; i++) p[i] = i;
        rank.assign(n, 0);
        sets = n;
    }

    int find_set(int i) { return (p[i] == i ? i : (p[i] = find_set(p[i]))); }
    bool is_same_set(int i, int j) { return (find_set(i) == find_set(j)); }
    void union_set(int i, int j) {
        if (!is_same_set(i, j)) {
            int x = find_set(i), y = find_set(j);
            if (rank[x] > rank[y]) swap(x, y);
            if (rank[x] == rank[y]) ++rank[y];
            p[x] = y;
            sets--;
        }
    }
    int num_of_sets() { return sets; }
};

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, mst_cost = 10000;
        cin >> n;

        vector<int> keys(n);
        for (int i = 0; i < n; i++) cin >> keys[i];

        vector<pair<int, pair<int, int>>> EL;
        for (int i = 0; i < keys.size(); i++) {
            mst_cost = min(mst_cost, num_of_rolls(0, keys[i]));

            for (int j = i + 1; j < keys.size(); j++) {
                EL.push_back({num_of_rolls(keys[i], keys[j]), {i, j}});
            }
        }

        sort(EL.begin(), EL.end());
        UFDS ufds(keys.size());
        for (int i = 0; i < EL.size() && ufds.num_of_sets() > 1; i++) {
            pair<int, pair<int, int>> e = EL[i];
            if (!ufds.is_same_set(e.second.first, e.second.second)) {
                mst_cost += e.first;
                ufds.union_set(e.second.first, e.second.second);
            }
        }

        cout << mst_cost << endl;
    }
}