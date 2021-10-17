/* Problem No. 606 */
// https://informatics.msk.ru/mod/statements/view.php?chapterid=606#1
// Date: 2021-10-17 14:38:07
// Max proccessor time: 0.004
// Max memory usage: 5746688
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
    bool union_sets(int i, int j) {
        int x = find_set(i), y = find_set(j);
        if (x == y) return false;

        if (rank[y] > rank[x]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        p[y] = x;
        --num_of_sets;

        return true;
    }
    int sets() { return num_of_sets; }
};

int main() {
    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> edges;
    UFDS ufds(n);
    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++) {
            int w; 
            cin >> w;
            if (u > v) {
                if (w == 0) ufds.union_sets(u, v);
                else edges.push_back({w, {u, v}});
            }
        }
    sort(edges.begin(), edges.end());


    int mst_cost = 0;
    for (int i = 0; i < edges.size() && ufds.sets() > 1; i++) {
        auto edge = edges[i];
        if (ufds.union_sets(edge.second.first, edge.second.second)) 
            mst_cost += edge.first;
    }

    cout << mst_cost << endl;
}