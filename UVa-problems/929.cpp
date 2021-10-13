/* UVa 929 - Number Maze */
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=678&page=show_problem&problem=870
// Date: 2021-08-30 11:24:28
// Runtime: 1.030
// Verdict: AC

#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
const int INF = 1e9;
const vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> maze(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> maze[i][j];
        
        priority_queue<iii, vector<iii>, greater<iii>> pq;
        pq.push({maze[0][0], 0, 0});
        vector<vector<int>> dist(n, vector<int>(m, INF));
        dist[0][0] = maze[0][0];
        while (!pq.empty()) {
            iii u = pq.top();
            pq.pop();

            if (get<0>(u) == dist[get<1>(u)][get<2>(u)]) {
                for (auto&& dir : dirs) {
                    ii v = {get<1>(u) + dir.first, get<2>(u) + dir.second};

                    if (0 <= v.first && v.first < n && 0 <= v.second && v.second < m) {
                        if (get<0>(u) + maze[v.first][v.second] < dist[v.first][v.second]) {
                            dist[v.first][v.second] = get<0>(u) + maze[v.first][v.second];
                            pq.push({dist[v.first][v.second], v.first, v.second});
                        }
                    }
                }
            }
        }
        cout << dist[n - 1][m - 1] << endl;
    }
}