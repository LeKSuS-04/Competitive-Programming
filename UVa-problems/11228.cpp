/* UVa 11228 - Transportation system. */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2169
// Date: 2021-08-27 07:20:43
// Runtime: 0.090
// Verdict: AC

#include <algorithm>
#include <cmath>
#include <cstdio>
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
        for (int i = 0; i < p.size(); i++) p[i] = i;
    }

    int find_set(int i) { return (p[i] == i ? i : (p[i] = find_set(p[i]))); }
    bool is_same_set(int i, int j) { return (find_set(i) == find_set(j)); }
    bool union_set(int i, int j) {
        if (is_same_set(i, j)) return false;

        int x = find_set(i), y = find_set(j);
        if (rank[x] > rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[y];
        p[x] = y;
        sets--;
        return true;
    }
    int num_of_sets() { return sets; }
};

int main() {
    int TC, case_n = 0;
    cin >> TC;
    while (TC--) {
        int n, r;
        cin >> n >> r;

        int x, y;
        vector<pair<int, int>> cities(n);
        for (int i = 0; i < n; i++) cin >> cities[i].first >> cities[i].second;

        vector<pair<double, pair<int, int>>> EL;
        for (int i = 0; i < cities.size(); i++) {
            for (int j = i + 1; j < cities.size(); j++) {
                double distance =
                    sqrt(pow(cities[i].first - cities[j].first, 2) +
                         pow(cities[i].second - cities[j].second, 2));
                EL.push_back({distance, {i, j}});
            }
        }

        sort(EL.begin(), EL.end());
        UFDS ufds(n);
        int states = 1;
        double roads_cost = 0, rails_cost = 0;
        for (int i = 0; i < EL.size() && ufds.num_of_sets() > 1; i++) {
            pair<double, pair<int, int>> e = EL[i];
            if (ufds.union_set(e.second.first, e.second.second)) {
                if (e.first > r) {
                    states++;
                    rails_cost += e.first;
                } else
                    roads_cost += e.first;
            }
        }

        printf("Case #%d: %d %d %d\n", ++case_n, states, int(roads_cost + 0.5), int(rails_cost + 0.5));
    }
}