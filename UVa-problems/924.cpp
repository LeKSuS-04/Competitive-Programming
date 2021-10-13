/* UVa 924 - Spreading the News */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=676&page=show_problem&problem=865
// Date: 2021-08-29 05:36:57
// Runtime: 0.000
// Verdict: AC

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
    int e, t;
    cin >> e;

    vector<vector<int>> AL(e, vector<int>());
    for (int i = 0; i < e; i++) {
        int n, j;
        cin >> n;
        while (n--) {
            cin >> j;
            AL[i].push_back(j);
        }
    }

    cin >> t;
    while (t--) {
        int k;
        cin >> k;

        queue<int> q;
        q.push(k);
        vector<int> bfs_num(e, INF), boom_num(e, 0);
        bfs_num[k] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto&& v : AL[u]) {
                if (bfs_num[v] == INF) {
                    bfs_num[v] = bfs_num[u] + 1;
                    ++boom_num[bfs_num[v]];
                    q.push(v);
                }
            }
        }

        pair<int, int> boom = {0, 0};
        for (int i = 0; i < boom_num.size(); i++) {
            if (boom_num[i] > boom.first) boom = {boom_num[i], i};
        }

        if (boom.first == 0)
            cout << 0 << endl;
        else
            cout << boom.first << " " << boom.second << endl;
    }
}