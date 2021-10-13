/* UVa 12047 - Highest Paid Toll */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=679&page=show_problem&problem=3198
// Date: 2021-08-31 06:19:11
// Runtime: 0.150
// Verdict: AC

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
const int INF = 1e9;

void dijkstra(vector<vector<ii>>& AL, vector<int>& dist, int start) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, start});
    dist.assign(AL.size(), INF);
    dist[start] = 0;
    while (!pq.empty()) {
        ii u = pq.top();
        pq.pop();

        if (u.first == dist[u.second]) {
            for (auto&& v : AL[u.second]) {
                if (u.first + v.second < dist[v.first]) {
                    dist[v.first] = u.first + v.second;
                    pq.push({dist[v.first], v.first});
                }
            }
        }
    }
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, m, s, t, p;
        cin >> n >> m >> s >> t >> p;

        vector<vector<ii>> AL(n);
        vector<vector<ii>> rev_AL(n);
        int u, v, w;
        while (m--) {
            cin >> u >> v >> w;
            AL[u - 1].push_back({v - 1, w});
            rev_AL[v - 1].push_back({u - 1, w});
        }

        vector<int> dist_start, dist_end;
        dijkstra(AL, dist_start, s - 1);
        dijkstra(rev_AL, dist_end, t - 1);

        int max_taka = -1;
        for (int u = 0; u < AL.size(); u++) {
            for (auto&& v : AL[u]) {
                if (dist_start[u] + v.second + dist_end[v.first] <= p) 
                    max_taka = max(max_taka, v.second);
            }
        }
        cout << max_taka << endl;
    }
}