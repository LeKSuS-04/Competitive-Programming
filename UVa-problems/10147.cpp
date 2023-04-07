/* UVa 10147 - Highways */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1088
// Date: 2021-08-27 10:51:04
// Runtime: 0.210
// Verdict: AC

#include <algorithm>
#include <cmath>
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
    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n;

        vector<pair<int, int>> coords(n);
        for (int i = 0; i < coords.size(); i++)
            cin >> coords[i].first >> coords[i].second;

        vector<pair<double, pair<int, int>>> EL;
        for (int i = 0; i < coords.size(); i++) {
            for (int j = i + 1; j < coords.size(); j++) {
                double distance =
                    sqrt(pow(coords[i].first - coords[j].first, 2) +
                         pow(coords[i].second - coords[j].second, 2));
                EL.push_back({distance, {i, j}});
            }
        }
        sort(EL.begin(), EL.end());

        UFDS ufds(n);
        int u, v;
        cin >> m;
        while (m--) {
            cin >> u >> v;
            ufds.union_set(u - 1, v - 1);
        }

        vector<pair<int, int>> new_highways;
        for (int i = 0; i < EL.size() && ufds.num_of_sets() > 1; i++) {
            auto e = EL[i];
            if (ufds.union_set(e.second.first, e.second.second))
                new_highways.push_back({e.second.first, e.second.second});
        }

        if (new_highways.size() == 0) {
            cout << "No new highways need\n";
        } else {
            for (auto&& nh : new_highways)
                cout << nh.first + 1 << " " << nh.second + 1 << endl;
        }
        if (TC) cout << endl;
    }
}