/* Problem No. 7 */
// https://informatics.msk.ru/mod/statements/view.php?chapterid=7#1
// Date: 2021-10-18 07:23:14
// Max proccessor time: 0.003
// Max memory usage: 5742592
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
    int n;
    cin >> n;

    vector<int> w(n);
    for (auto&& wi : w) cin >> wi;

    int k; cin >> k;
    vector<vector<int>> AL(n);
    while (k--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        AL[u].push_back(v);
        AL[v].push_back(u);
    }

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    int src = 0, dst = n - 1;
    vector<int> dist(n, INF);
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        ii u = pq.top(); pq.pop();
        if (u.first != dist[u.second]) continue;

        for (auto&& v : AL[u.second]) {
            if (dist[u.second] + w[u.second] < dist[v]) {
                dist[v] = dist[u.second] + w[u.second];
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[dst] == INF) cout << "-1\n";
    else cout << dist[dst] << endl;
}