/* UVa 10305 - Ordering Tasks */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=668&page=show_problem&problem=1246
// Date: 2021-08-22 08:01:44
// Runtime: 0.000
// Verdict: AC

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int UNVISITED = 0;
const int VISITED = 1;

vector<int> used;
vector<vector<int>> AL;
vector<int> sorted; 

void toposort(int v) {
    if (used[v] == VISITED) return;
    used[v] = VISITED;

    for (int i = 0; i < AL[v].size(); i++) {
        toposort(AL[v][i]);
    }
    sorted.push_back(v + 1);
}

int main() {
    int n, m, u, v;

    while (cin >> n >> m, n | m) {
        used.assign(n, UNVISITED);
        AL.assign(n, vector<int>());
        sorted.clear();

        while (m--) {
            cin >> u >> v;
            AL[u - 1].push_back(v - 1);
        }

        for (int i = 0; i < used.size(); i++) {
            if (used[i] == UNVISITED) {
                toposort(i);
            }
        }

        for (auto it = sorted.rbegin(); it != sorted.rend(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
}