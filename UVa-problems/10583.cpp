/* UVa 10583 - Ubiquitous Religions */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1524
// Date: 2021-08-18 04:55:10
// Run time: 0.160
// Verdict: AC

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

class UFDS {
private:
    vector<int> p, rank;
    int num_of_sets;
public:
    UFDS(int n) {
        p.assign(n + 1, 0); for (int i = 1; i <= n; i++) p[i] = i;
        rank.assign(n + 1, 0);
        num_of_sets = n;
    }

    int find_set(int i) { return (p[i] == i ? i : (p[i] = find_set(p[i]))); }
    bool is_same_set(int a, int b) { return find_set(a) == find_set(b); }
    void union_set(int a, int b) {
        if (!is_same_set(a, b)) {
            int x = find_set(a), y = find_set(b);
            if (rank[x] > rank[y]) swap(x, y);
            if (rank[x] == rank[y]) ++rank[y];
            p[x] = y;
            --num_of_sets;
        }
    }
    int count() { return num_of_sets; }
};

int main() {
    int n, m, a, b, c = 0;

    while (cin >> n >> m, n | m) {
        UFDS ufds(n);

        while (m--) {
            cin >> a >> b;
            ufds.union_set(a, b);
        }

        printf("Case %d: %d\n", ++c, ufds.count());
    }
}