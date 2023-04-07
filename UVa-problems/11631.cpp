/* UVa 11631 - Dark roads */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=673&page=show_problem&problem=2678
// Date: 2021-08-27 07:39:45
// Runtime: 0.390
// Verdict: AC

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class UFDS {
   private:
    int sets;
    vector<int> p, rank;

   public:
    UFDS(int n) {
        sets = n;
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
        --sets;

        return true;
    }
    int num_of_sets() { return sets; }
};

int main() {
    int n, m;
    while (cin >> n >> m, n | m) {
        int u, v, w, total = 0, mst_cost = 0;
        vector<pair<int, pair<int, int>>> EL(m);
        for (int i = 0; i < EL.size(); i++) {
            cin >> u >> v >> w;
            EL[i] = {w, {u, v}};
            total += w;
        }

        sort(EL.begin(), EL.end());
        UFDS ufds(m);
        for (int i = 0; i < EL.size() && ufds.num_of_sets() > 1; i++) {
            auto e = EL[i];
            if (ufds.union_set(e.second.first, e.second.second))
                mst_cost += e.first;
        }

        cout << total - mst_cost << endl;
    }
}