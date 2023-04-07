/* Problem No. 5 */
// https://informatics.msk.ru/mod/statements/view.php?chapterid=5#1
// Date: 	2021-10-18 07:05:20
// Max proccessor time: 0.006
// Max memory usage: 2031616
// Verdict: AC

#include <iostream>
using namespace std;

int main() {
    
}

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;

const int INF = 1e9;

int main() {
    int n, src, dst;
    cin >> n >> src >> dst;
    --src; --dst;

    vector<vector<ii>> AL(n);
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            int w;
            cin >> w;
            if (w > 0) AL[u].push_back({v, w});
        }
    }

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vector<int> dist(n, INF);
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        ii u = pq.top(); pq.pop();

        if (u.first != dist[u.second]) continue;

        for (auto&& v : AL[u.second]) {
            if (dist[v.first] > dist[u.second] + v.second) {
                dist[v.first] = dist[u.second] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }

    if (dist[dst] == INF) cout << "-1\n";
    else cout << dist[dst] << endl;
}