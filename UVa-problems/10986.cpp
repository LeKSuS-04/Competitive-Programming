/* UVa 10986 */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=678&page=show_problem&problem=1927
// Date: 2021-08-30 10:26:05
// Runtime: 0.300
// Verdict: vi

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

const int INF = 1e9;

int main() {
    int TC, case_n = 0;
    cin >> TC;
    while (TC--) {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        
        vector<vector<ii>> AL(n);

        int u, v, w;
        while (m--) {
            cin >> u >> v >> w;
            AL[u].push_back({v, w});
            AL[v].push_back({u, w});
        }

        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push({s, 0});
        vector<int> dist(n, INF);
        dist[s] = 0;
        while (!pq.empty()) {
            ii u = pq.top();
            pq.pop();

            if (dist[u.first] == u.second) {
                for (auto&& v : AL[u.first]) {
                    if (dist[u.first] + v.second < dist[v.first]) {
                        dist[v.first] = dist[u.first] + v.second;
                        pq.push({v.first, dist[v.first]});
                    }
                }
            }
        } 

        cout << "Case #" << ++case_n << ": ";
        if (dist[t] == INF) cout << "unreachable\n";
        else cout << dist[t] << endl;
    }
}