/* UVa 558 - Wormholes */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=680&page=show_problem&problem=499
// Date: 2021-08-31 08:09:02
// Runtime: 0.080
// Verdict: AC

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
const int INF = 1e9;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n >> m;

        vector<vector<ii>> AL(n);
        int u, v, w;
        while (m--) {
            cin >> u >> v >> w;
            AL[u].push_back({v, w});
        }

        vector<int> dist(n, INF);
        dist[0] = 0;
        for (int _ = 0; _ < n - 1; _++) {
            for (int u = 0; u < AL.size(); u++) {
                for (auto&& v : AL[u]) {
                    dist[v.first] = min(dist[v.first], dist[u] + v.second);
                }
            }
        }

        bool has_negative_cycle = false;
        for (int u = 0; u < AL.size(); u++) {
            for (auto&& v : AL[u]) {
                if (dist[u] + v.second < dist[v.first]) has_negative_cycle = true;
            }
        }

        cout << (has_negative_cycle ? "possible" : "not possible") << endl;
    }
}