/* UVa 12160 - Unlock the Lock */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=677&page=show_problem&problem=3312
// Date: 2021-08-29 11:15:03
// Runtime: 0.010
// Verdict: AC

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
    int l, u, r, case_n = 0;
    while (cin >> l >> u >> r, r | l | u) {
        vector<int> rots(r);
        for (int i = 0; i < r; i++) cin >> rots[i];
        
        vector<int> bfs_num(1e4, INF);
        queue<int> q;
        q.push(l);
        bfs_num[l] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto&& rot : rots) {
                int v = (u + rot) % 10000;
                if (bfs_num[v] == INF) {
                    bfs_num[v] = bfs_num[u] + 1;
                    q.push(v);
                }
            }
        }

        cout << "Case " << ++case_n << ": ";
        if (bfs_num[u] == INF) cout << "Permanently Locked\n";
        else cout << bfs_num[u] << endl;
    }
}