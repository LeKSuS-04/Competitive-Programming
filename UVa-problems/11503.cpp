/* UVa 11503 - Virtual Friends */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2498
// Date: 2021-08-17 16:07:58
// Run time: 0.830
// Verdict: AC

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class UFDS  {
private:
    unordered_map<string, string> p;
    unordered_map<string, int> f, rank;
public:
    void add(string a, string b) { 
        p.insert({{a, a}, {b, b}});
        f.insert({{a, 1}, {b, 1}});
        rank.insert({{a, 0}, {b, 0}});
    }

    string find_set(string i) { return (p[i] == i ? i : (p[i] = find_set(p[i]))); }
    bool is_same_set(string a, string b) { return find_set(a) == find_set(b); }
    void union_set(string a, string b) {
        if (!is_same_set(a, b)) {
            string x = find_set(a),
                   y = find_set(b);
            if (rank[x] > rank[y]) swap(x, y);
            p[x] = y;
            f[y] += f[x];
            if (rank[x] == rank[y]) ++rank[y];
        }
    }
    int get_friends(string a) { return f[find_set(a)]; }
};

int main() {
    int TC, n;
    string a, b;
    cin >> TC;

    while (TC--) {
        cin >> n;
        UFDS ufds;

        while (n--) {
            cin >> a >> b;
            ufds.add(a, b);

            ufds.union_set(a, b);
            cout << ufds.get_friends(a) << '\n';
        }
    }
}