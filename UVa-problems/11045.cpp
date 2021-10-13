/* UVa 11045 - My T-shirt suits me */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1986
// Date: 2021-09-09 15:28:19
// Runtime: 0.000
// Verdict: AC

#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

const int S = 0;
const int T = 1;
const int MAXSIZE = 50;
const int INF = 1e9;

const map<string, int> sizes = {
    {"XS",  2},
    {"S",   3},
    {"M",   4},
    {"L",   5},
    {"XL",  6},
    {"XXL", 7}
};

int max_flow;
vector<int> p;
bitset<MAXSIZE> visited;
vector<vector<int>> AL, AM;
int augment(int v, int bottleneck) {
    if (v == S) return bottleneck;
    else {
        bottleneck = augment(p[v], min(bottleneck, AM[p[v]][v]));
        AM[p[v]][v] -= bottleneck;
        AM[v][p[v]] += bottleneck;
        return bottleneck;
    }
}
void edmonds_karp() {
    max_flow = 0;
    
    while (true) {
        queue<int> q;
        visited.reset();
        p.assign(AL.size(), -1);

        q.push(S);
        visited[S] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto&& v : AL[u]) {
                if (!visited[v] && AM[u][v] > 0) {
                    visited[v] = true;
                    p[v] = u;
                    q.push(v);
                }
            }
        }

        if (p[T] == -1) break;
        max_flow += augment(T, INF);
    }
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n >> m;
        
        AL.assign(8 + m, vector<int>());
        AM.assign(8 + m, vector<int>(8 + m, 0));

        for (int i = 2; i < 8; i++) {
            AL[i].push_back(T);
            AM[i][T] = n / 6;
        }
        for (int i = 0; i < m; i++) {
            AL[S].push_back(8 + i);
            AM[S][8 + i] = 1;
        }
        for (int i = 0; i < m; i++) {
            string a, b;
            cin >> a >> b;
            int x = sizes.at(a), y = sizes.at(b);

            AL[8 + i].push_back(x);
            AL[8 + i].push_back(y);
            AL[x].push_back(8 + i);
            AL[y].push_back(8 + i);
            AM[8 + i][x] = INF;
            AM[8 + i][y] = INF;
        }

        edmonds_karp();

        if (max_flow == m) cout << "YES\n";
        else cout << "NO\n";
    }
}