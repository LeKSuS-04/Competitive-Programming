/* UVa 1197 - The Suspects */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3638
// Date: 2021-08-18 04:36:45
// Run time: 0.000
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

class UFDS {
private:
    vector<int> p, rank, s;
public:
    UFDS(int n) {
        p.assign(n, 0); for (int i = 0; i < n; i++) p[i] = i;
        rank.assign(n, 0);
        s.assign(n, 1);
    }

    int find_set(int i) { return (p[i] == i ? i : (p[i] = find_set(p[i]))); }
    bool is_same_set(int a, int b) { return find_set(a) == find_set(b); }
    void union_set(int a, int b) {
        if (!is_same_set(a, b)) {
            int x = find_set(a),
                y = find_set(b);
            if (rank[x] > rank[y]) swap(x, y);
            if (rank[x] == rank[y]) ++rank[y];
            p[x] = y;
            s[y] += s[x];
        }
    }
    int get_size(int i) { return s[find_set(i)]; }
};

int main() {
    int n, m, k;
    vector<int> group;

    while (cin >> n >> m, n | m) {
        UFDS ufds(n);

        while (m--) {
            cin >> k;
            group.assign(k, -1);
            
            for (int i = 0; i < k; i++) cin >> group[i];
            for (int i = 1; i < k; i++) ufds.union_set(group[i - 1], group[i]);
        }

        cout << ufds.get_size(0) << endl;
    }
}