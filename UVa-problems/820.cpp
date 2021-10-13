/* UVa 820 - Internet Bandwidth */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=761
// Date: 2021-09-05 15:15:52
// Runtime: 0.000
// Verdict: AC

#include <bitset>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9;
const int MAXSIZE = 110;

bitset<MAXSIZE> unvisited;
int max_flow, f, s, t;
vector<vector<int>> AM;
vector<int> p;

void augment(int v, int min_edge) {
    if (v == s) { f = min_edge; }
    else if (p[v] != INF) { 
        augment(p[v], min(min_edge, AM[p[v]][v])); 
        AM[p[v]][v] -= f;
        AM[v][p[v]] += f;
    }
}

int main() {
    int n, case_n = 0;
    while (cin >> n, n) {
        int e;
        cin >> s >> t >> e;
        --s, --t;
        
        int u, v, w;
        p.assign(n, INF);
        AM.assign(n, vector<int>(n, 0));
        vector<vector<int>> AL(n);
        while (e--) {
            cin >> u >> v >> w;
            --u, --v;
            AM[u][v] += w;
            AM[v][u] += w;
            AL[v].push_back(u);
            AL[u].push_back(v);
        }

        max_flow = 0, f = 42;
        while (f != 0) {
            f = 0;

            unvisited.set();
            unvisited[s] = false;
            queue<int> q;
            q.push(s);
            p.assign(n, INF);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == t) break;
                for (auto&& v : AL[u]) 
                    if (AM[u][v] > 0 && unvisited[v]) {
                        unvisited[v] = false;
                        p[v] = u;
                        q.push(v);
                    }
            }

            augment(t, INF);
            max_flow += f;
        }

        cout << "Network " << ++case_n << endl;
        cout << "The bandwidth is " << max_flow << ".\n\n";
    }
}