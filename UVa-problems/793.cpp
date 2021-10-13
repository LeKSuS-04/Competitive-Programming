/* UVa 793 - Network Connections */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=734
// Date: 2021-08-17 14:12:48
// Run time: 0.110
// Verdict: AC

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class UFDS {
private:
    vector<int> p, rank;
public:
    UFDS(int size) { 
        p.assign(size + 1, -1); for (int i = 1; i < size + 1; i++) p[i] = i;
        rank.assign(size + 1, 0);
    }

    int find_set(int i) { return (p[i] == i ? i : (p[i] = find_set(p[i]))); }
    bool is_same_set(int a, int b) { return find_set(a) == find_set(b); }
    void union_sets(int a, int b) {
        if (!is_same_set(a, b)) {
            int x = find_set(a),
                y = find_set(b);

            if (rank[x] > rank[y]) swap(x, y);
            p[x] = y;
            if (rank[x] == rank[y]) ++rank[y];
        }
    }
};

int main() {
    int TC, n, s, f, a, b;
    char t;
    string in;

    scanf("%d\n", &TC);
    while (TC--) {
        scanf("%d\n", &n);
        UFDS ufds(n);

        s = f = 0;
        while (getline(cin, in), !in.empty()) {
            istringstream iss(in);
            iss >> t >> a >> b;

            if (t == 'c') ufds.union_sets(a, b);
            else if (t == 'q') {
                if (ufds.is_same_set(a, b)) ++s;
                else ++f;
            }
        }

        printf("%d,%d\n", s, f);
        if (TC) cout << '\n';
    }
}