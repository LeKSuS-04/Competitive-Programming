/* UVa 1112 - Mice and Maze */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=678&page=show_problem&problem=3553
// Date: 2021-08-30 10:56:12
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
const int INF = 1e9;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, e, t, m;
        cin >> n >> e >> t >> m;
        --e;

        vector<vector<ii>> AL(n);

        int u, v, w;
        while (m--) {
            cin >> u >> v >> w;
            AL[v - 1].push_back({u - 1, w});
        }

        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push({0, e});
        vector<int> dist(n, INF);
        dist[e] = 0;
        while (!pq.empty()) {
            ii u = pq.top();
            pq.pop();

            if (dist[u.second] == u.first) {
                for (auto&& v : AL[u.second]) {
                    if (u.first + v.second < dist[v.first]) {
                        dist[v.first] = u.first + v.second;
                        pq.push({dist[v.first], v.first});
                    }
                }
            }
        }

        int escaped = 0;
        for (auto&& d : dist) 
            if (d <= t) escaped++;
        cout << escaped << endl;
        if (TC) cout << endl;
    }
}