/* UVa 10048 - Audiophobia */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=674&page=show_problem&problem=989
// Date: 2021-08-27 09:56:29
// Runtime: 0.010
// Verdict: AC

#include <algorithm>
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
        for (int i = 0; i < n; i++) p[i] = i;
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

const int UNVISITED = 0;
const int VISITED = 1;
const int DESTINATION_PATH = 2;

int max_db;
vector<vector<pair<int, int>>> AL;
vector<int> dfs_num;

void dfs(int u, int destination) {
    if (u == destination) {
        dfs_num[u] = DESTINATION_PATH; 
        return;
    }
    
    dfs_num[u] = VISITED;

    for (auto&& v :AL[u]) {
        if (dfs_num[v.first] == UNVISITED) {
            dfs(v.first, destination);

            if (dfs_num[v.first] == DESTINATION_PATH) {
                max_db = max(max_db, v.second);
                dfs_num[u] = DESTINATION_PATH;
                return;
            }
        }
    }
}

int main() {
    int c, s, q, case_n = 0;
    while (cin >> c >> s >> q, c | s | q) {
        AL.assign(c, vector<pair<int, int>>());

        vector<pair<int, pair<int, int>>> EL;
        int u, v, w;
        while (s--) {
            cin >> u >> v >> w;
            EL.push_back({w, {u - 1, v - 1}});
        }
        sort(EL.begin(), EL.end());

        UFDS ufds(c);
        for (int i = 0; i < EL.size() && ufds.num_of_sets() > 1; i++) {
            auto e = EL[i];
            if(ufds.union_set(e.second.first, e.second.second)) {
                AL[e.second.first].push_back({e.second.second, e.first});
                AL[e.second.second].push_back({e.second.first, e.first});
            }
        }

        if (case_n != 0) cout << endl;
        printf("Case #%d\n", ++case_n);
        while (q--) {
            cin >> u >> v;

            if (ufds.is_same_set(u - 1, v - 1)) {
                max_db = -1;
                dfs_num.assign(c, 0);

                dfs(u - 1, v - 1);
                cout << max_db << endl;
            } else {
                cout << "no path\n";
            }
        }
    }
}