/* UVa 10557 - XYZZY */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=680&page=show_problem&problem=1498
// Date: 2021-08-31 15:01:45
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

const int UNVISITED = 0;
const int VISITED = 1;

vector<vector<int>> AL;
vector<int> energy;

bool reachable(int from, int to) {
    vector<int> visited(AL.size(), UNVISITED);
    visited[from] = VISITED;
    queue<int> q;
    q.push(from);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto&& v : AL[u]) {
            if (visited[v] == UNVISITED) {
                q.push(v);
                visited[v] = VISITED;
            }
        }
    }
    return (visited[to] == VISITED);
} 

int main() {
    int n;
    while (cin >> n, n != -1) {
        int m, v;

        AL.assign(n, vector<int>());
        energy.assign(n, 0);

        for (int i = 0; i < n; i++) {
            cin >> energy[i] >> m;
            while (m--) {
                cin >> v;
                AL[i].push_back(v - 1);
            }
        }
        
        vector<int> dist(n, 0);
        dist[0] = 100;

        for (int i = 0; i < n - 1 ; i++) {
            for (int u = 0; u < AL.size(); u++) {
                if (dist[u] > 0) {
                    for (auto&& v : AL[u]) {
                        if (dist[u] + energy[v] > dist[v]) {
                            dist[v] = dist[u] + energy[v];
                        }
                    }
                }
            }
        }

        bool is_winnable = (dist[n - 1] != 0);
        for (int u = 0; u < AL.size() && !is_winnable; u++) {
            if (dist[u] > 0) {
                for (auto&& v : AL[u]) {
                    if (dist[u] + energy[v] > dist[v]) {
                        if (reachable(v, n - 1)) is_winnable = true;
                    }
                }
            }
        }
        if (is_winnable) cout << "winnable\n";
        else cout << "hopeless\n";
    }
}