/* UVa 11690 - Money Matters */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2737
// Date: 2021-08-18 15:27:24
// Run time: 0.160
// Verdict: AC

#include <iostream>
#include <vector>
using namespace std;

class UFDS {
private:
    vector<int> p, rank, s;
public:
    UFDS(int n, const vector<int> o) {
        p.assign(n, 0); for (int i = 0; i < n; i++) p[i] = i;
        rank.assign(n, 0);
        s = o;
    }

    int find_set(int i) { return (p[i] == i ? i : (p[i] = find_set(p[i]))); }
    bool is_same_set(int a, int b) { return find_set(a) == find_set(b); }
    void union_set(int a, int b) {
        if (!is_same_set(a, b)) {
            int x = find_set(a), y = find_set(b);
            if (rank[x] > rank[y]) swap(x, y);
            if (rank[x] == rank[y]) ++rank[y];
            p[x] = y;
            s[y] += s[x];
        }
    }
    bool is_possible() {
        for (int i = 0; i < p.size(); i++) {
            if (s[find_set(i)] != 0) return false;
        }
        return true;
    }
};

int main() {
    int TC, n, m, x, y;
    vector<int> o;

    cin >> TC;
    while (TC--) {
        cin >> n >> m;

        o.assign(n, 0);
        for (int i = 0; i < n; i++) cin >> o[i];

        UFDS ufds(n, o);
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            ufds.union_set(x, y);
        }

        cout << (ufds.is_possible() ? "POSSIBLE" : "IMPOSSIBLE") << "\n";
    }
}