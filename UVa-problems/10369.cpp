/* UVa 10369 - Arctic Network */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1310
// Date: 2021-08-27 11:47:13
// Runtime: 0.020
// Verdict: AC

#include <algorithm>
#include <cmath>
#include <iomanip>
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

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int s, p;
        cin >> s >> p;

        vector<pair<int, int>> coords(p);
        for (int i = 0; i < p; i++) cin >> coords[i].first >> coords[i].second;

        vector<pair<double, pair<int, int>>> EL;
        for (int i = 0; i < coords.size(); i++) {
            for (int j = i + 1; j < coords.size(); j++) {
                double d = sqrt(pow(coords[i].first - coords[j].first, 2) +
                                pow(coords[i].second - coords[j].second, 2));
                EL.push_back({d, {i, j}});
            }
        }
        sort(EL.begin(), EL.end());

        UFDS ufds(p);
        double D;
        for (int i = 0; i < EL.size() && ufds.sets() > s; i++) {
            auto e = EL[i];
            if (ufds.union_set(e.second.first, e.second.second)) D = e.first;
        }

        cout << setprecision(2) << fixed << D << endl;
    }
}