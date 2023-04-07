/* Problem No. 605 */
// https://informatics.msk.ru/mod/statements/view.php?chapterid=605#1
// Date: 2021-10-13 19:50:57
// Max proccessor time: 0.004
// Max memory usage: 2035712
// Verdict: AC

#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;

double dist(pair<int, int> a, pair<int, int> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

class UFDS {
private:
    int num_of_sets;
    vector<int> p, rank;

public:
    UFDS(int n) {
        p.resize(n);
        for (int i = 0; i < n; i++) p[i] = i;
        rank.assign(n, 0);
        num_of_sets = n;
    } 

    int find_set(int i) { return (p[i] == i ? i : (p[i] = find_set(p[i]))); }
    bool union_sets(int i, int j) {
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
    int n, m;
    scanf("%d", &n);

    vector<pair<int, int>> points(n);
    for (auto&& p : points)
        scanf("%d %d", &p.first, &p.second);

    vector<pair<double, pair<int, int>>> edges;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            edges.push_back({dist(points[i], points[j]), {i, j}});

    sort(edges.begin(), edges.end());

    UFDS ufds(n);
    scanf("%d", &m);
    while (m--) {
        int i, j;
        scanf("%d %d", &i, &j);
        ufds.union_sets(i - 1, j - 1);
    }

    double mst_cost = 0;
    for (int i = 0; i < edges.size() && ufds.sets() > 1; i++) {
        auto e = edges[i];
        if (ufds.union_sets(e.second.first, e.second.second)) 
            mst_cost += e.first;
    }

    printf("%.5f\n", mst_cost);
}