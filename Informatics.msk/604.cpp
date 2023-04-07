/* Problem No. 604 */
// https://informatics.msk.ru/mod/statements/view.php?chapterid=604#1
// Date: 2021-10-13 19:34:54
// Max proccessor time: 0.006
// Max memory usage: 364544
// Verdict: AC

#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

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
    bool is_same_set(int i, int j) { return find_set(i) == find_set(j); }
    void union_sets(int i, int j) {
        int x = find_set(i), y = find_set(j);
        if (x == y) return;
        if (rank[y] > rank[x]) swap(x, y);

        if (rank[x] == rank[y]) ++rank[x];
        p[y] = x;
        --num_of_sets;
    }
    int sets() { return num_of_sets; }
};

int main() {
    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> edges;
    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++) {
            int w; 
            cin >> w;
            if (u > v) edges.push_back({w, {u, v}});
        }
    sort(edges.begin(), edges.end());

    UFDS ufds(n);
    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++) {
            bool connected;
            cin >> connected;
            if (u > v && connected) ufds.union_sets(u, v);
        }

    int mst_cost = 0;
    for (int i = 0; i < edges.size() && ufds.sets() > 1; i++) {
        auto edge = edges[i];
        if (!ufds.is_same_set(edge.second.first, edge.second.second)) {
            ufds.union_sets(edge.second.first, edge.second.second);
            mst_cost += edge.first;
        }
    }

    cout << mst_cost << endl;
}