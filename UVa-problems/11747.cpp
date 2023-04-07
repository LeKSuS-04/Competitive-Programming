/* UVa 11747 - Heavy Cycle Edges */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2847
// Date: 2021-08-27 07:55:43
// Runtime: 0.000
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
    int n, m;
    while (cin >> n >> m, n | m) {
        int u, v, w;
        vector<pair<int, pair<int, int>>> EL;
        while (m--) {
            cin >> u >> v >> w;
            EL.push_back({w, {u, v}});
        }

        sort(EL.begin(), EL.end());
        UFDS ufds(n);
        int cycles = 0;
        for (auto&& e : EL) {
            if (!ufds.union_set(e.second.first, e.second.second)) {
                if (cycles++ != 0) cout << " ";
                cout << e.first;
            }
        }
        if (cycles == 0) cout << "forest";
        cout << endl;
    }
}