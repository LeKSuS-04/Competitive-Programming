/* UVa 1234 - RACING */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=674&page=show_problem&problem=3675
// Date: 2021-08-27 09:17:17
// Runtime: 0.150
// Verdict: AC

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class UFDS {
   private:
    vector<int> p, rank;

   public:
    UFDS(int n) {
        rank.assign(n, 0);
        p.assign(n, 0);
        for (int i = 0; i < n; i++) p[i] = i;
    }

    int find_set(int i) { return (p[i] == i ? i : (p[i] = find_set(p[i]))); }
    bool is_same_set(int i, int j) { return (find_set(i) == find_set(j)); }
    bool union_set(int i, int j) {
        if (is_same_set(i, j)) return false;

        int x = find_set(i), y = find_set(j);
        if (rank[x] > rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[y];
        p[x] = y;

        return true;
    }
};

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, pair<int, int>>> EL;
        int u, v, w;
        while (m--) {
            cin >> u >> v >> w;
            EL.push_back({w, {u - 1, v - 1}});
        }
        sort(EL.begin(), EL.end(), greater<pair<int, pair<int, int>>>());

        UFDS ufds(n);
        int mst_cost = 0;
        for (auto&& e : EL) {
            if (!ufds.union_set(e.second.first, e.second.second))
                mst_cost += e.first;
        }
        cout << mst_cost << endl;
    }
    cin >> TC;
}