/* UVa 908 - Re-connecting Computeer Sites */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=673&page=show_problem&problem=849
// Date: 2021-08-27 05:50:27
// Runtime: 0.000
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
        p.assign(n, 0); for (int i = 0; i < p.size(); i++) p[i] = i;
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
    int n, m, k, case_n = 0;
    while (cin >> n) {
        int u, v, w, prev_cost = 0, mst_cost = 0;

        for (int i = 0; i < n - 1; i++) {
            cin >> u >> v >> w;
            prev_cost += w;
        }
        
        vector<pair<int, pair<int, int>>> EL;
        cin >> k;
        while (k--) {
            cin >> u >> v >> w;
            EL.push_back({w, {u - 1, v - 1}});
        }
        cin >> m;
        while (m--) {
            cin >> u >> v >> w;
            EL.push_back({w, {u - 1, v - 1}});
        }

        sort(EL.begin(), EL.end());
        UFDS ufds(n);
        for (int i = 0; i < EL.size() && ufds.num_of_sets() > 1; i++) {
            pair<int, pair<int, int>> e = EL[i];
            if (!ufds.is_same_set(e.second.first, e.second.second)) {
                mst_cost += e.first;
                ufds.union_set(e.second.first, e.second.second);
            }
        }

        if (case_n++ != 0) cout << endl;
        cout << prev_cost << endl << mst_cost << endl;
    }
}