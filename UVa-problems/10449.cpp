/* UVa 10449 - Traffic */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=680&page=show_problem&problem=1390
// Date: 2021-08-31 15:56:13
// Runtime: 0.000
// Verdict: AC

#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
const int INF = 1e9;
const int UNVISITED = 0;
const int VISITED = 1;

vector<vector<ii>> AL;

bool reachable(int from, int to) {
    vector<int> visited(AL.size(), UNVISITED);
    visited[from] = VISITED;
    queue<int> q;
    q.push(from);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto&& v : AL[u]) {
            if (visited[v.first] == UNVISITED) {
                visited[v.first] = VISITED;
                q.push(v.first);
            }
        }
    }
    return (visited[to] == VISITED);
}

int main() {
    int n, r, u, v, q, case_n = 0;
    while (cin >> n) {
        if (n == 0) {
            cin >> r >> q;
            cout << "Set #" << ++case_n << endl;
            continue;
        }

        vector<int> business(n);
        for (int i = 0; i < n; i++) cin >> business[i];

        AL.assign(n, vector<ii>());

        cin >> r;
        while (r--) {
            cin >> u >> v;
            AL[u - 1].push_back({v - 1, pow(business[v - 1] - business[u - 1], 3)});
        }

        vector<int> dist(n, INF);
        dist[0] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int u = 0; u < AL.size(); u++) {
                for (auto&& v : AL[u]) {
                    dist[v.first] = min(dist[v.first], dist[u] + v.second);
                }
            }
        }

        vector<int> neg_cycles;
        for (int u = 0; u < AL.size(); u++) {
            for (auto&& v : AL[u]) {
                if (dist[u] + v.second < dist[v.first])
                    neg_cycles.push_back(v.first);
            }
        }

        cin >> q;
        cout << "Set #" << ++case_n << endl;
        while (q--) {
            cin >> v; --v;
            bool has_cycle_way = false;
            for (auto&& u : neg_cycles) {
                if (reachable(u, v)) {
                    has_cycle_way = true;
                    break;
                }
            }

            if (has_cycle_way || dist[v] < 3 || !reachable(0, v)) cout << "?\n";
            else cout << dist[v] << endl;
        }
    }
}