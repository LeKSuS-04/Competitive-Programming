/* UVa 10462 - Is There A Second Way Left? */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1403
// Date: 2021-08-27 13:03:54
// Runtime: 0.040
// Verdict: AC

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class UFDS {
   private:
    int num_of_sets;
    vector<int> p, rank;

   public:
    UFDS(int n) {
        num_of_sets = n;
        rank.assign(n, 0);
        p.assign(n, 0);
        for (int i = 0; i < n; i++) p[i] = i;
    }

    int find_set(int i) { return (p[i] == i ? i : (p[i] = find_set(p[i]))); }
    bool union_set(int i, int j) {
        int x = find_set(i), y = find_set(j);
        if (x == y) return false;

        if (rank[x] > rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[y];
        p[x] = y;
        --num_of_sets;

        return true;
    }
    int sets() { return num_of_sets; }
};

const int INF = 10000000;

int n, m;
vector<pair<int, pair<int, int>>> EL;
vector<int> mst_edge_idx;
vector<bool> available;

int calc_mst(bool save_edges) {
    UFDS ufds(n);
    int mst_cost = 0;
    for (int i = 0; i < EL.size(); i++) {
        if (available[i]) {
            auto e = EL[i];
            if (ufds.union_set(e.second.first, e.second.second)) {
                mst_cost += e.first;
                if (save_edges) mst_edge_idx.push_back(i);
            }
        }
    }
    if (ufds.sets() == 1) return mst_cost;
    else return INF;
}

int main() {
    int TC, case_n = 0;
    cin >> TC;
    while (TC--) {
        cin >> n >> m;

        EL.clear();
        mst_edge_idx.clear();
        int u, v, w;
        while (m--) {
            cin >> u >> v >> w;
            EL.push_back({w, {u - 1, v - 1}});
        }
        sort(EL.begin(), EL.end());
        available.assign(EL.size(), true);

        int mst_first, mst_second = INF;
        mst_first = calc_mst(true);
        for (int i = 0; i < mst_edge_idx.size(); i++) {
            available[mst_edge_idx[i]] = false;
            mst_second = min(mst_second, calc_mst(false));
            available[mst_edge_idx[i]] = true;
        }

        cout << "Case #" << ++case_n << " : ";
        if (mst_first == INF) cout << "No way\n";
        else if (mst_second == INF) cout << "No second way\n";
        else cout << mst_second << endl;
    }
}